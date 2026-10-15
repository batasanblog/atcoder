ll f_4sha5nyu(ll x,ll k){
	ll p=1;
	rep(i,k-1)p*=10;
	return (x+5*p)/(p*10)*(p*10);
}
