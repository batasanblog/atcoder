// Topological sort
// faster version 2026/9/5
vl topological_sort_original(vector<vl>&g){
	vl ret;
	vl deg(at(g));
	for(auto u:g)for(auto v:u)at(deg,v)++;
	queue<ll>q;
	rep(i,at(g))if(at(deg,i)==0)q.push(i);
	while(!q.empty()){
		ll u=q.front();q.pop();
		ret.pb(u);
		for(auto v:at(g,u)){
			assert(at(deg,v));
			at(deg,v)--;
			if(at(deg,v)==0){
				q.push(v);
			}
		}
	}
	return ret;
}
// If ret.size() < N, there must be strongly connected components(loop).

/* old version
template<typename T>bool chmax(T &a,T b){return a<b?a=b,true:false;}
template<typename T>bool chmin(T &a,T b){return a>b?a=b,true:false;}
vl topological_sort(vector<vl> &g, vl &dis){
	vl ret;
	unordered_map<ll,ll> mp;
	for(auto u:g)for(auto v:u) mp[v]++;
	priority_queue<ll,vl,greater<ll>> qu;
	rep(i,g.size())if(!mp.count(i)) qu.push(i);
	while(!qu.empty()){
		ll u = qu.top();qu.pop();
		ret.pb(u);
		for(auto v:g.at(u)){
			assert(mp[v] > 0);
			mp[v]--;
			chmax(dis.at(v),dis.at(u)+1);
			if(mp[v] == 0){
				qu.push(v);
			}
		}
	}
	return ret;
}
*/
// End Topological sort
