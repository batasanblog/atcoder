// LCA lowest common ancestor
struct lca{
	vector<vl>to,dp;  //dp:doubling
	vl d; // depth
	lca(ll _n):to(_n){}
	void add_edge(ll u,ll v){
		at(to,u).pb(v); 
		at(to,v).pb(u); 
	}

	void init(ll s=0){ // s:root
		ll sz=to.size();
		ll k = 1; 
		while((1LL<<k)<sz) k++;
		dp.resize(k,vl(sz,-1));
		d.resize(sz,-1);
		dfs(s);
		rep(i,k-1){
			rep(u,sz){
				if(at(dp,i,u)<0){
					at(dp,i+1,u)=-1;
				}else{
					at(dp,i+1,u)=at(dp,i,at(dp,i,u));
				}
			}
		}
		#ifdef DEBUG
		show("d",d);show("dp",dp);
		#endif
	}
	//
	void dfs(ll u,ll p=-1,ll x=0){ // p:parent
		at(dp,0,u)=p;
		d.at(u)=x;
		for(auto v:at(to,u)){
			if(v!=p)dfs(v,u,x+1);
		}
	}
	//
	ll query(ll u,ll v){
		if(at(d,u)<at(d,v))swap(u,v);
		ll k=dp.size();
		rep(i,k){
			if((at(d,u)-at(d,v))>>i&1)u=at(dp,i,u);
		}
		if(u==v)return u;
		for(ll i=k-1;i>=0;--i){
			if(at(dp,i,u)!=at(dp,i,v)){
				u=at(dp,i,u);
				v=at(dp,i,v);
			}
		}
		return at(dp,0,u);
	}
};
/* LCA
auto logic(){
	ll N,Q;
	cin>>N>>Q;
	lca a(N);
	reps(v,1,N){
		ll u;cin>>u;--u;
		a.add_edge(u,v);
	}
	a.init();
	string anss;
	rep(qi,Q){
		ll u,v;cin>>u>>v;--u;--v;
		anss+=to_string(a.query(u,v)+1)+"\n";
	}
	cout<<anss;
	return;
}
*/
/*
	 get max w from u-v path ABC235E

	 struct lca{
	 vector<vl>dp,mx;  //dp:doubling
	 vector<vector<pl>>to;  //dp:doubling
	 vl d; // depth
	 lca(ll _n):to(_n){}
	 void add_edge(ll u,ll v,ll w){
		 at(to,u).eb(v,w); 
		 at(to,v).eb(u,w); 
	 }

	 void init(ll s=0){ // s:root
		 ll sz=to.size();
		 ll k = 1; 
		 while((1LL<<k)<sz) k++;
		 dp.resize(k,vl(sz,-1));
		 d.resize(sz,-1);
		 mx.resize(k,vl(sz));
		 dfs(s);
		 rep(i,k-1){
			 rep(u,sz){
				 if(at(dp,i,u)<0){
					 at(dp,i+1,u)=-1;
				 }else{
					 at(mx,i+1,u)=max(at(mx,i,at(dp,i,u)),at(mx,i,u));
					 at(dp,i+1,u)=at(dp,i,at(dp,i,u));
				 }
			 }
		 }
		 #ifdef DEBUG
		 show("d",d);
		 show("dp");show(dp);
		 show("mx");show(mx);
		 #endif
	 }
	 //
	 void dfs(ll u,ll p=-1,ll x=0){ // p:parent
		 at(dp,0,u)=p;
		 d.at(u)=x;
		 for(auto[v,w]:at(to,u)){
			 if(v==p)continue;
			 at(mx,0,v)=w;
			 dfs(v,u,x+1);
		 }
	 }
	 //
	 ll query(ll u,ll v){
		 show("q",u,v);
		 if(at(d,u)<at(d,v))swap(u,v);
		 ll k=dp.size();
		 ll mxu=0,mxv=0;
		 rep(i,k){
			 if((at(d,u)-at(d,v))>>i&1){
				 chmax(mxu,at(mx,i,u));
				 u=at(dp,i,u);
			 }
		 }
		 if(u==v)return mxu;
		 for(ll i=k-1;i>=0;--i){
			 if(at(dp,i,u)!=at(dp,i,v)){
				 chmax(mxu,at(mx,i,u));
				 chmax(mxv,at(mx,i,v));
				 u=at(dp,i,u);
				 v=at(dp,i,v);
			 }
		 }
		 chmax(mxu,at(mx,0,u));
		 chmax(mxv,at(mx,0,v));
		 show(u,v,"mx",mxu,mxv);
		 return max(mxu,mxv);
	 }
 };
	 */

