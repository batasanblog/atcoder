// Rerooting
// https://youtu.be/zG1L4vYuGrg?t=7092
// TODO: vertex info, edge info
struct Rerooting {
	struct DP {
		mint dp;
		DP(mint dp=1):dp(dp) {}
		DP operator+(const DP& a) const {
			return DP(dp*a.dp);
		}
		DP& operator+=(const DP& a) {
			dp*=a.dp; return *this;
		}
		DP addRoot() const {
			return DP(dp+1);
		}
	};

	ll n;
	vector<vector<ll>> to;
	vector<vector<DP>> dp;
	vector<DP> ans;
	Rerooting(ll _n=0):n(_n),to(_n),dp(_n),ans(_n) {}
	void addEdge(ll a, ll b) {
		to[a].push_back(b);
		to[b].push_back(a);
	}
	void init() {
		dfs(0);
		bfs(0);
	}

	DP dfs(ll u,ll p=-1){
		DP dpSum;
		dp[u]=vector<DP>(to[u].size());
		rep(i,to[u].size()){
			ll v=to[u][i];
			if(v==p)continue;
			dp[u][i]=dfs(v,u);
			dpSum=dpSum+dp[u][i];
		}
		return dpSum.addRoot();
	}
	void bfs(ll u,const DP& dpP=DP(),ll p=-1){
		ll deg=to[u].size();
		rep(i,deg)if(to[u][i]==p)dp[u][i]=dpP;

		vector<DP>dpSumL(deg+1);
		rep(i,deg)dpSumL[i+1]=dpSumL[i]+dp[u][i];
		vector<DP>dpSumR(deg+1);
		for(ll i=deg-1;i>=0;--i)
			dpSumR[i]=dpSumR[i+1]+dp[u][i];
		ans[u]=dpSumL[deg].addRoot();

		rep(i,deg){
			ll v=to[u][i];
			if(v==p)continue;
			DP d=dpSumL[i]+dpSumR[i+1];
			bfs(v,d.addRoot(),u);
		}
	}
};
/*
{
	Rerooting rr(N);
	rep(n,N-1){
		ll u,v;cin>>u>>v;--u;--v;
		rr.addEdge(u,v);
	}
	rr.init();
	for(auto e:rr.ans)cout<<e.dp.val()<<'\n';
}
*/
