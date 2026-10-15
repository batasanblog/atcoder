// Lowest Common Ancestor by binary lifting
// https://youtu.be/8uowVvQ_-Mo?t=4306
template<typename T=int> // T: type of cost
struct lca{
	int n,root,l;
	vector<vector<int>>to;
	vector<vector<T>>co;
	vector<int>dep;
	vector<T>costs;
	vector<vector<int>>par;
	lca(){}
	lca(int _n):n(_n),to(_n),co(_n),dep(_n),costs(_n){
		l=0;
		while((1<<l)<n)++l;
		par=vector<vector<int>>(n+1,vector<int>(l,n));
	}
	void addEdge(int a,int b,T c=0){
		to[a].push_back(b);co[a].push_back(c);
		to[b].push_back(a);co[b].push_back(c);
	}
	void dfs(int v,int d=0,T c=0,int p=-1){
		if(p!=-1)par[v][0]=p;
		dep[v]=d;
		costs[v]=c;
		for(int i=0;i<int(to[v].size());++i){
			int u=to[v][i];
			if(u==p)continue;
			dfs(u,d+1,c+co[v][i],v);
		}
	}

	void init(int _root=0){
		root=_root;
		dfs(root);
		for(int i=0;i<l-1;++i){
			for(int v=0;v<n;++v){
				par[v][i+1]=par[par[v][i]][i];
			}
		}
	}
	// LCA
	int up(int v,int k){
		for(int i=l-1;i>=0;--i){
			int len=1<<i;
			if(k>=len)k-=len,v=par[v][i];
		}
		return v;
	}
	int operator()(int a,int b){
		if(dep[a]>dep[b])swap(a,b);
		b=up(b,dep[b]-dep[a]);
		if(a==b)return a;
		for(int i=l-1;i>=0;--i){
			int na=par[a][i],nb=par[b][i];
			if(na!=nb)a=na,b=nb;
		}
		return par[a][0];
	}
	int length(int a,int b){
		int c=(*this)(a,b);
		return dep[a]+dep[b]-dep[c]*2;
	}
	T dist(int a,int b){
		int c=(*this)(a,b);
		return costs[a]+costs[b]-costs[c]*2;
	}
};
// Auxiliary Tree
struct auxiliary_tree{
	lca<int> g;
	vector<pl>eul; // first show, last show
	auxiliary_tree(ll _n):g(_n),eul(_n){}

	void addEdge(ll u,ll v){
		g.addEdge(u,v);
	}
	
	void init(){
		g.init();
		ll now=0;
		auto dfs=[&](auto f,ll u,ll p=-1)->void{
			at(eul,u).fi=now++;
			for(auto v:at(g.to,u)){
				if(v==p)continue;
				f(f,v,u);
			}
			at(eul,u).se=now++;
		};
		dfs(dfs,0);
	}

	auto comp0(vl&vs,vector<vector<ll>>&dag){
		sort(be(vs),[&](ll a,ll b){
				return at(eul,a).fi<at(eul,b).fi;
				});
		ll sz=vs.size();

		vl st; //stock
		st.pb(at(vs,0));
		rep(i,sz-1){
			ll w=g(at(vs,i),at(vs,i+1));
			if(w!=at(vs,i)){
				ll last=st.back();st.pop_back();
				while(!st.empty()&&g.dep[w]<g.dep[st.back()]){
					at(dag,st.back()).eb(last);
					last=st.back();st.pop_back();
				}
				if(st.empty()||st.back()!=w){
					st.pb(w);
					vs.pb(w);
					at(dag,w)=vl();
				}
				at(dag,w).pb(last);
			}
			st.pb(at(vs,i+1));
			at(dag,at(vs,i+1))=vl();
		}
		while(st.size()>=2){
			auto i1=st.rbegin();
			auto i0=i1+1;
			at(dag,*i0).pb(*i1);
			st.pop_back();
		}
		return st.front();
	}
};
/* typical90-035

auto logic(){
	ll N,Q;cin>>N;
	lca g;
	auxiliary_tree auxt(N);
	rep(n,N-1){
		ll u,v;cin>>u>>v;--u;--v;
		auxt.addEdge(u,v);
	}
	auxt.init();

	cin>>Q;
	string anss;
	vector<vector<ll>>dag(N);
	rep(qi,Q){
		ll k;cin>>k;
		vl v(k);
		rep(i,k){
			cin>>at(v,i),at(v,i)--;
			at(dag,at(v,i))=vl();
		}
		auto s=auxt.comp0(v,dag);
		//
		auto dfs=[&](auto f,ll u)->ll{
			ll r=0;
			for(auto w:at(dag,u)){
				r+=f(f,w)+auxt.g.length(u,w);
			}
			return r;
		};
		auto ans=dfs(dfs,s);
		anss+=to_string(ans)+"\n";
	}
	cout<<anss<<endl;

	return 0;
}
*/
