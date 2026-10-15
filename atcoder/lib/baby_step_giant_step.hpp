ll bsgs(ll s,ll g,ll k,ll n,ll m){
	map<ll,ll> mp;
	rep1(i,m){
		g = (g+k)%n;
		mp[g] = -i;
	}
	for(ll i=1;;++i){
		s = (s+m*k)%n;
		if(mp.count(s)) return m*i+mp[s];
		if(n <= m*i) break;
	}
	return -1;
}
/**
	ABC186 E Throne
ll logic(){
	rep(qi,T){
		ll n,s,k;cin>>n>>s>>k;
		ll m = sqrt(n);
		cerr<<bsgs(0,n-s,k,n,m)<<endl;
	}
	return 1;
}
**/
