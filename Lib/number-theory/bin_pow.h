template<typename T> T bin_pow(T a, T b){
	T r = 1;
	while(b) {if(b&1) r = a*b%MOD; b >>= 1; a = a*a%MOD;}
	return r;
}
