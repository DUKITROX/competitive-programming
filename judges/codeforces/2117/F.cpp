#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

const int MOD = 1e9+7;

template<typename T> T bin_pow(T a, T b){
	T r = 1;
	while(b) {if(b&1) r = a*b%MOD; b >>= 1; a = a*a%MOD;}
	return r;
}

template <typename T>
T inverse(T a, T m) {
	T u = 0, v = 1;
	while (a != 0) {
		T t = m / a;
		m -= t * a; swap(a, m);
		u -= t * v; swap(u, v);
	}
	assert(m == 1);
	return u;
}

template <typename T>
class Modular {
	public:
		using Type = typename decay<decltype(T::value)>::type;

		constexpr Modular() : value() {}
		template <typename U>
			Modular(const U& x) {
				value = normalize(x);
			}

		template <typename U>
			static Type normalize(const U& x) {
				Type v;
				if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
				else v = static_cast<Type>(x % mod());
				if (v < 0) v += mod();
				return v;
			}

		const Type& operator()() const { return value; }
		template <typename U>
			explicit operator U() const { return static_cast<U>(value); }
		constexpr static Type mod() { return T::value; }

		Modular& operator+=(const Modular& other) { value += other.value; value -= (value >= mod()) * mod(); return *this; }
		Modular& operator-=(const Modular& other) { value -= other.value; value += (value < 0) * mod(); return *this; }
		template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
		template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
		Modular& operator++() { return *this += 1; }
		Modular& operator--() { return *this -= 1; }
		Modular operator++(int) { Modular result(*this); *this += 1; return result; }
		Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
		Modular operator-() const { return Modular(-value); }

		template <typename U = T>
			typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
				value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
				return *this;
			}
		template <typename U = T>
			typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
				int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
				value = normalize(value * rhs.value - q * mod());
				return *this;
			}
		template <typename U = T>
			typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
				value = normalize(value * rhs.value);
				return *this;
			}

		Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

		friend const Type& abs(const Modular& x) { return x.value; }

		template <typename U>
			friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

		template <typename U>
			friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

		template <typename V, typename U>
			friend V& operator>>(V& stream, Modular<U>& number);

	private:
		Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
	assert(b >= 0);
	Modular<T> x = a, res = 1;
	U p = b;
	while (p > 0) {
		if (p & 1) res *= x;
		x *= x;
		p >>= 1;
	}
	return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
	return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
	return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
	return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
	typename common_type<typename Modular<T>::Type, int64_t>::type x;
	stream >> x;
	number.value = Modular<T>::normalize(x);
	return stream;
}

// using ModType = int;

// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;

constexpr int md = int(1e9) + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

// vector<Mint> fact(1, 1);
// vector<Mint> inv_fact(1, 1);

// Mint C(int n, int k) {
//   if (k < 0 || k > n) {
//     return 0;
//   }
//   while ((int) fact.size() < n + 1) {
//     fact.push_back(fact.back() * (int) fact.size());
//     inv_fact.push_back(1 / fact.back());
//   }
//   return fact[n] * inv_fact[k] * inv_fact[n - k];
// }


void solve(){
	int n; cin >> n;
	vector<vector<int>> adj(n); vector<int> deg(n);
	int leaves = 0;
	for(int i = 0; i < n-1; i++){
		int u,v; cin >> u >> v; u--; v--; 
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++; deg[v]++;
	}
	for(auto e : deg) if(e == 1) leaves++;
	if(leaves > 3 || leaves == 3 && deg[0] != 1) cout << "0\n";
	else if(leaves == 2 && deg[0] == 1) cout << power((Mint)2,n) << "\n";
	else{
		vector<int> h(n), le; h[0] = 0;
		int M = -1, H = 0;
		auto dfs = [&](auto&& self, int u, int p)->void{
			if(deg[u] > 2) M = u;
			else if(deg[u] == 1 && u != 0) le.push_back(u);

			for(auto v : adj[u]){
				if(v != p) {
					ckmax(H,h[v] = h[u] + 1);
					self(self, v, u);
				}
			}
		};
		dfs(dfs, 0, -1);

		int L = max(h[le[0]], h[le[1]]), l = min(h[le[0]], h[le[1]]);
		if(M != -1) L -= h[M], l -= h[M];

		Mint sol = power((Mint)2, n-L-l);
		if(L == l) sol *= (Mint)2;
		else sol *= (power((Mint)2, L-l) + power((Mint)2, L-l-1));
		cout << sol << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

