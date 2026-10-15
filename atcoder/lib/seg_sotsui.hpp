// ABC342G Retroactive Range Chmax
struct seg_sotsui{
	ll n;
	vector<set<pl>>d;
	seg_sotsui(ll _n):n(_n),d(_n*2){}

	void ins(ll x,ll a,ll b){
		if(b<0)at(d,x).erase({a,-b});
		else at(d,x).emplace(a,b);
	}

	void upd(ll l,ll r,ll a,ll b){
		for(l+=n,r+=n;l!=r;l=(l+1)>>1,r>>=1){
			if(l&1)ins(l,a,b);
			if(r&1)ins(r-1,a,b);
		}
	}

	ll get(ll x){
		x+=n;
		ll ret=-INF;
		while(x){
			auto it=at(d,x).end();
			if(at(d,x).size())ret=max(ret,(--it)->fi);
			x>>=1;
		}
		return ret;
	}

};
/*
ll logic(){
	seg_sotsui seg(N);
	rep(n,N)seg.upd(n,n+1,at(A,n),0);
	using T=tuple<ll,ll,ll>;
	vector<T>qs(Q+1);
	for(ll qi=1;qi<=Q;qi++){
		ll t;cin>>t;
		if(t==1){
			ll l,r,x;cin>>l>>r>>x;--l;
			seg.upd(l,r,x,qi);
			at(qs,qi)=T(l,r,x);
		}else if(t==2){
			ll i;cin>>i;
			auto[l,r,x]=at(qs,i);
			seg.upd(l,r,x,-i);
		}else{
			ll i;cin>>i;
			cout<<seg.get(i-1)<<'\n';
		}
	}
	#ifdef DEBUG
	cerr << "--- Answer ---" << endl;
	#endif
	return 1;
}
*/
