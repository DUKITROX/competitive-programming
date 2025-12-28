#!/usr/bin/env python3
import sys
import math
import random
import subprocess
from collections import defaultdict

# ----------------------------
# Bandwidth model
# ----------------------------
def bandwidth_at(t, B, phi):
    t = (t + phi) % 10
    if t in [0, 1, 8, 9]:
        return 0.0
    elif t in [2, 7]:
        return B / 2.0
    else:
        return B

# ----------------------------
# Read input
# ----------------------------
def read_input(path):
    with open("./tests/"+path) as f:
        M, N, FN, T = map(int, f.readline().split())
        uavs = {}
        for _ in range(M * N):
            x, y, B, phi = f.readline().split()
            x, y, phi = int(x), int(y), int(phi)
            B = float(B)
            uavs[(x, y)] = (B, phi)
        flows = []
        for line in f:
            if not line.strip():
                continue
            f_id, x, y, start_t, s, m1, n1, m2, n2 = map(int, line.split())
            flows.append({
                "f": f_id, "x": x, "y": y, "t_start": start_t, "size": s,
                "m1": m1, "n1": n1, "m2": m2, "n2": n2
            })
    return M, N, FN, T, uavs, flows

# ----------------------------
# Euclidean hop distance
# ----------------------------
def hops(ax, ay, bx, by):
    return abs(ax - bx) + abs(ay - by)

# ----------------------------
# Parse solver output
# ----------------------------
def parse_output(text):
    lines = text.strip().splitlines()
    idx = 0
    result = {}
    while idx < len(lines):
        parts = lines[idx].split()
        if len(parts) < 2:
            idx += 1
            continue
        f_id, p = int(parts[0]), int(parts[1])
        idx += 1
        sched = []
        for _ in range(p):
            t, x, y, z = lines[idx].split()
            t, x, y = int(t), int(x), int(y)
            z = float(z)
            sched.append((t, x, y, z))
            idx += 1
        result[f_id] = sched
    return result

# ----------------------------
# Scoring
# ----------------------------
def evaluate_flow(flow, sched, uavs, T):
    if not sched:
        return 0.0

    total_s = flow["size"]
    t_start = flow["t_start"]
    access_x, access_y = flow["x"], flow["y"]

    # Weighted components
    total_u2g_traffic = sum(z for (_, _, _, z) in sched)
    total_u2g_score = total_u2g_traffic / total_s

    # Delay score
    delay_sum = 0.0
    for t, x, y, z in sched:
        delay_sum += (10 / (t + 10)) * (z / total_s)
    delay_score = delay_sum

    # Distance score
    distance_sum = 0.0
    for t, x, y, z in sched:
        d = hops(access_x, access_y, x, y)
        distance_sum += (z / total_s) * (2 ** (-0.1 * d))
    distance_score = distance_sum

    # Landing UAV changes
    landing_points = [(x, y) for (_, x, y, _) in sched if z > 0]
    changes = 1
    if landing_points:
        last = landing_points[0]
        for p in landing_points[1:]:
            if p != last:
                changes += 1
                last = p
    landing_score = 1.0 / changes

    total_score = 100.0 * (
        0.4 * total_u2g_score +
        0.2 * delay_score +
        0.3 * distance_score +
        0.1 * landing_score
    )
    return total_score

# ----------------------------
# Evaluate all flows
# ----------------------------
def evaluate_all(M, N, FN, T, uavs, flows, sched):
    total_weight = sum(f["size"] for f in flows)
    total_score = 0.0
    for flow in flows:
        sc = evaluate_flow(flow, sched.get(flow["f"], []), uavs, T)
        total_score += (flow["size"] / total_weight) * sc
    return total_score

# ----------------------------
# Generate random input for local runs (optional)
# ----------------------------
def generate_input(seed, path="input.txt"):
    random.seed(seed)
    M, N = random.randint(50, 70), random.randint(50, 70)
    FN, T = random.randint(1000,3000), random.randint(100, 300)
    with open(path, "w") as f:
        f.write(f"{M} {N} {FN} {T}\n")
        for x in range(M):
            for y in range(N):
                B = random.uniform(10, 100)
                phi = random.randint(0, 9)
                f.write(f"{x} {y} {B:.2f} {phi}\n")
        for fid in range(1, FN + 1):
            x, y = random.randrange(M), random.randrange(N)
            s = random.randint(10, 300)
            t0 = random.randint(0, T//2)
            m1, n1 = random.randint(0, M-1), random.randint(0, N-1)
            m2 = random.randint(m1, min(M-1, m1+20))
            n2 = random.randint(n1, min(N-1, n1+20))
            f.write(f"{fid} {x} {y} {t0} {s} {m1} {n1} {m2} {n2}\n")

# ----------------------------
# Main
# ----------------------------
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: tester.py <seed>")
        sys.exit(1)
    seed = int(sys.argv[1])
    input_path = f"input_{seed}.txt"
    generate_input(seed, "./tests/"+input_path)

    # Run solver
    try:
        proc = subprocess.run(["./sol2"], input=open("./tests/"+input_path).read().encode(),
                            stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=20)
        #print("Return code:", proc.returncode)
        #print("STDOUT:\n", proc.stdout.decode())
        #print("STDERR:\n", proc.stderr.decode())
        output = proc.stdout.decode()

    except Exception as e:
        import traceback
        traceback.print_exc()
        print("Exception:", e)
        print("score: 0.0 (exception)")
        sys.exit(0)


    # Evaluate
    M, N, FN, T, uavs, flows = read_input(input_path)
    sched = parse_output(output)
    score = evaluate_all(M, N, FN, T, uavs, flows, sched)

    print(f"score: {score}")

