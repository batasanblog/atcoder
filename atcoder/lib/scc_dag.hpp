//convert scc to dag
struct scc_dag{
	ll n,sz;
	scc_graph g;
	vector<vector<int>>scc;
	vector<vl>to,dag;
	vector<vl>rev;
	vl ind;
	scc_dag(){}
	scc_dag(ll _n):n(_n){
		g=scc_graph(n);
		to=vector<vl>(n);
	}
	void add_edge(ll u,ll v){
		at(to,u).pb(v);
		g.add_edge(u,v);
	}
	void init(){
		scc=g.scc();
		sz=at(scc);
		ind=vl(n);
		rep(i,sz){
			for(auto j:at(scc,i)){
				at(ind,j)=i;
			}
		}
		dag=vector<vl>(sz);
		rev=vector<vl>(sz);
		rep(u,sz){
			unordered_set<ll>st;
			for(auto i:at(scc,u)){
				for(auto j:at(to,i))st.insert(at(ind,j));
			}
			for(auto v:st)if(u!=v){
				at(dag,u).pb(v);
				at(rev,v).pb(u);
			}
		}
	}
	ll size(){return sz;}
	ll size(ll u){return at(at(scc,u));}
};


//function version
void scc_dag(auto&to,auto&scc,auto&dag,auto&sizes){
	ll sz=scc.size();
	sizes.resize(sz);
	dag.resize(sz);
	map<ll,ll>mp;
	rep(i,sz)for(auto j:at(scc,i))mp[j]=i;
	rep(u,sz){
		at(sizes,u)=at(scc,u).size();
		unordered_set<ll>st;
		for(auto i:at(scc,u)){
			//rep(j,N)if(at(A,i,j))st.insert(mp[j]);
			for(auto j:at(to,i))st.insert(mp[j]);
		}
		for(auto v:st)if(u!=v)at(dag,u).pb(v);
	}
}
/*
ll logic(){
	scc_graph g(N);
	rep(u,N){
		for(auto v:at(to,u))g.add_edge(u,v);
	}	
	auto scc=g.scc();
	ll sz=scc.size();
	vector<vl>dag(sz);
	vl weight(sz);
	scc_dag(to,scc,dag,weight);
}
*/	
