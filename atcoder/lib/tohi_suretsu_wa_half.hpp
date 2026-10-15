// Tohi Suretsu Wa
ll mpow(ll x, ll n) {
	ll ret = 1;
	while (n > 0) {
		if (n & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		n >>= 1; 
	}
	return ret;
}
ll smr(ll n,ll r){
	if(n == 1) return 1; // shoki chi
	ll ret;
	ll m = n/2;
	if(n & 1){
		ret = ((smr(m,r) * (1 + mpow(r,m)))%MOD + mpow(r,n-1))%MOD;
	}else{
		ret = ((smr(m,r) * (1 + mpow(r,m)))%MOD)%MOD;
	}
	return ret;
}
/**
ll logic(){
	ll ans = smr(N,R);
	return ans;
}
**/
