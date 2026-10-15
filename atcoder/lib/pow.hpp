ll floor_sqrt(ll x){
	ll ac=1,wa=x+1;
	while(ac+1<wa){
		ll wj=(ac+wa)/2;
		if(wj>x/wj||wj*wj>x)wa=wj;
		else ac=wj;
	#ifdef DEBUG0
		show(x,":",ac,wa,wj,wj*wj);
	#endif
	}
	return ac;
}
mint pow2(ll x){
	static vector<mint> v(1,1);
	while(v.size() < x+1){
		v.pb(v.back()*2);
	#ifdef DEBUG0
		show("x sz",x,v.size());
	#endif
	}
	return v.at(x);
}
mint mpow(mint x, ll n) {
	mint ret = 1;
	while(n > 0) {
		if(n & 1) ret *= x;
		x *= x;
		n >>= 1; 
	}
	return ret;
}
ll modpow(ll x,ll n,ll m){
	x%=m;
	ll ret=1;
	while(n>0){
		if(n&1) ret=__int128(ret)*x%m;
		x=__int128(x)*x%m;
		n>>=1; 
	}
	return ret;
}
// by snuke
mint pow_by_half(mint x, ll t) {
	if (t == 0) return 1;
	if (t%2 == 1) {
		return pow_by_half(x,t-1)*x;
	} else {
		mint y = pow_by_half(x,t/2);
		return y*y;
	}
}
/**
int main() {
    long long x, n;
    cin >> x >> n;
    cerr << pow(x, n) << endl;
    return 0;
}**/
// mpow : mod power
