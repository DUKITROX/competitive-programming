import random

def generate_input(seed, path="input.txt"):
    random.seed(seed)
    M, N = random.randint(3, 6), random.randint(3, 6)
    FN, T = random.randint(2, 5), random.randint(30, 60)
    with open(path, "w") as f:
        f.write(f"{M} {N} {FN} {T}\n")
        for x in range(M):
            for y in range(N):
                B = random.uniform(50, 200)
                phi = random.randint(0, 9)
                f.write(f"{x} {y} {B:.2f} {phi}\n")
        for fid in range(1, FN + 1):
            x, y = random.randrange(M), random.randrange(N)
            s = random.randint(100, 500)
            t0 = random.randint(0, T // 2)
            m1, n1 = random.randint(0, M//2), random.randint(0, N//2)
            m2, n2 = random.randint(m1, M-1), random.randint(n1, N-1)
            f.write(f"{fid} {x} {y} {t0} {s} {m1} {n1} {m2} {n2}\n")

def main():
    generate_input(321312)

if __name__ == "__main__":
    main()