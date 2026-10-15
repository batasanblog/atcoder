// Snuke SCC
// upstream is smaller id
struct scc {
	ll n, k;
	vector<vl> to, ot, d, gt; // to, rev_to, groups, group_to
	vl g, used, kv; // group, gomi, topo_ord
	scc(ll n=0):n(n),to(n),ot(n){}
	ll inc() { to.pb(vl()); ot.pb(vl()); return n++;}
	void add(ll a, ll b) { to[a].pb(b); ot[b].pb(a);}
	void dfs(ll v) {
		if (used[v]) return;
		used[v] = 1;
		rep(i,to[v].size()) dfs(to[v][i]);
		kv[--k] = v;
	}
	void rfs(ll v) {
		if (g[v] != -1) return;
		g[v] = k; d[k].pb(v);
		rep(i,ot[v].size()) rfs(ot[v][i]);
	}
	void init() {
		k = n;
		used = kv = vl(n);
		g = vl(n,-1);
		rep(i,n) dfs(i);
		rep(i,n) if (g[kv[i]] == -1)  {
			d.pb(vl());
			rfs(kv[i]);
			k++;
		}
		gt = vector<vl>(k);
		rep(i,n)rep(j,ot[i].size()) {
			ll v = g[ot[i][j]], u = g[i];
			if (v != u) gt[v].pb(u);
		}
		rep(i,k) {
			sort(be(gt[i]));
			gt[i].erase(unique(be(gt[i])),gt[i].end());
		}
	}
};
//
