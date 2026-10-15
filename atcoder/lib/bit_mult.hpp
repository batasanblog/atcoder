// AWC0082E BIT(Fenwick Tree) Multi
struct bit_multi{
	ll n;
	vector<vl>v0;
	vector<vl>v1;
	bit_multi(ll _n):n(_n),v0(_n+1),v1(_n+1){}
	// input i:0-index
	void add(ll i,ll x){
		i++; // 1-index
		while(i<=n){
			at(v0,i).pb(x);
			i+=i&-i;
		}
	}
	void init(){
		rep1(i,n){
			auto&w=at(v0,i);
			sort(be(w));
			w.erase(unique(be(w)),w.end());
			at(v1,i).resize(at(w)+1);
		}
	}
	// input i:0-index
	void set(ll i,ll x,ll d){
		i++; // 1-index
		while(i<=n){
			auto&w=at(v0,i);
			ll j=lower_bound(be(w),x)-w.begin()+1;
			while(j<at(at(v1,i))){
				show(" i",i,"j",j);
				at(v1,i,j)+=d;
				j+=j&-j;
			}
			i+=i&-i;
		}
	}
	// input (l,r]
	ll sum(ll l,ll r,ll x){
		return sum(r,x)-sum(l,x);
	}
	void print(){
		show("v0");show(v0);
		show("v1");show(v1);
	}
private: 
	// internal: i:1-index
	ll sum(ll i,ll x){
		ll ret=0;
		while(i>0){
			auto&w=at(v0,i);
			ll j=upper_bound(be(w),x)-w.begin();
			while(j>0){
				ret+=at(v1,i,j);
				j-=j&-j;
			}
			i-=i&-i;
		}
		return ret;
	}
};
/*
auto logic(){
	ll N,Q;
	cin>>N>>Q;
	vl A(N);rep(n,N)cin>>at(A,n);
	vector<vl>to(N);
	reps(v,1,N){
		ll u;cin>>u;--u;
		at(to,u).pb(v);
	}
	show(N,Q,A);show(to);
	vector<pl>eu(N);
	ll now=0;
	auto dfs=[&](auto f,ll u)->void{
		at(eu,u).fi=now++;
		for(auto v:at(to,u)){
			f(f,v);
		}
		at(eu,u).se=now;
	};
	dfs(dfs,0);
	show("eu",eu);
	bit_multi bit(N+1);
	rep(n,N){
		bit.add(at(eu,n).fi,at(A,n));
	}
	using T=tuple<ll,ll,ll>;
	vector<T>qs(Q);
	rep(qi,Q){
		ll t;cin>>t;
		if(t==1){
			ll v,x;cin>>v>>x;--v;
			at(qs,qi)=T(t,v,x);
			bit.add(at(eu,v).fi,x);
		}else{
			ll v;cin>>v;--v;
			at(qs,qi)=T(t,v,-1);
		}
	}
	bit.init();
	rep(n,N){
		bit.set(at(eu,n).fi,at(A,n),1);
	}
	bit.print();

	string anss;
	rep(qi,Q){
		auto[t,v,x]=at(qs,qi);
		if(t==1){
			ll l=at(eu,v).fi;
			bit.set(l,at(A,v),-1);
			bit.set(l,x,1);
			at(A,v)=x;
		}else{
			ll l=at(eu,v).fi,r=at(eu,v).se;
			//ll rsum=bit.sum(r,at(A,v));
			//ll lsum=bit.sum(l,at(A,v));
			ll ans=r-l-bit.sum(l,r,at(A,v));
			show(" rl",r,l,"sum",bit.sum(l,r,at(A,v)));
			anss+=to_string(ans)+="\n";
		}
	}
	cout<<anss;
	return;
}
*/
