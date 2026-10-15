vl n_adic(ll x,ll n){
	vl ret;
	while(x > 0){
		ret.pb(x%n);
		x /= n;
	}
}
