vl prime_number(ll n){
	vector<bool>p(n+1,true);
	vl r;
	reps(i,2,n+1){
		if(!at(p,i))continue;
		r.pb(i);
		for(ll j=i+i;j<=n;j+=i)at(p,j)=false;
	}
	return r;
}
/*
vl prime_number(const ll N) {
	vector<bool> is_prime(N+1,true);
 	vector<ll> re;
	for(ll i=2;i<=N;i++) {
    if(is_prime.at(i)) {
      for(ll j=2*i;j<=N;j+=i) {
        is_prime.at(j) = false;
    	}
    	re.eb(i);
  	}
	}
	return re;
}
*/
