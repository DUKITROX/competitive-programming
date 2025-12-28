/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed (max-tree). Bounds are inclusive to the left and exclusive to the right.
 * Can be changed by modifying T, f and unit.
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

template<typename T = int>
struct STree {
	using F = function<T(const T&, const T&)>;
	F f; vector<T> s; int n; T unit;
	STree(int n, F f = std::min, T def = INT_MAX) : s(2*n, def), n(n), f(f) , unit(def){}
	STree(const vector<T>& v, F f, T def) : n(v.size()) , f(f), unit(def){
		s.resize(2 * n);
		for (int i = 0; i < n; ++i) s[n + i] = v[i];
		for (int i = n - 1; i > 0; --i) s[i] = f(s[2 * i], s[2 * i + 1]);
	}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

