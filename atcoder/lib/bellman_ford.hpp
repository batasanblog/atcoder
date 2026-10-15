using tl = tuple<ll,ll,ll>;
template<typename T>inline bool chmax(T &a,T b){return a<b?a=b,true:false;}
template<typename T>inline bool chmin(T &a,T b){return a>b?a=b,true:false;}
bool bellman_ford(vector<tl> &edge,ll n,ll s,vl &d){ // d must be INF
	d.at(s) = 0;
	rep(i,n){
		bool fin = true;
		for(auto e:edge){
			auto [u,v,c] = e;
			if(chmin(d.at(v),d.at(u) + c)) fin = false;
		}
		if(fin) break;
		if(i == n-1) return true; // hu heiro ari
	}
	return false;
}
