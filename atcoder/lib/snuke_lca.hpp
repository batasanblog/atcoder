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
	void addEdge(int a,int b,T c=1){
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
/*
	 ABC405F

int main() {
  int n, m;
  cin >> n >> m;
  n *= 2;

  vector<int> dif(n);
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    dif[a] = 1; dif[b] = -1;
  }

  using P = pair<int,int>;
  vector<P> edges;
  vector<int> vid(n);
  int vs = 1;
  {
    vector<int> st = {0};
    rep(i,n) {
      if (dif[i] == 0) {
        vid[i] = st.back();
      } else {
        if (dif[i] == 1) {
          edges.emplace_back(st.back(),vs);
          st.push_back(vs); vs++;
        } else {
          st.pop_back();
        }
      }
    }
  }

  lca g(vs);
  for (auto [a,b] : edges) g.addEdge(a,b);
  g.init();

  int q;
  cin >> q;
  rep(qi,q) {
    int c,d;
    cin >> c >> d;
    c--; d--;
    int ans = g.length(vid[c],vid[d]);
    cout << ans << '\n';
  }
  return 0;
}
*/
