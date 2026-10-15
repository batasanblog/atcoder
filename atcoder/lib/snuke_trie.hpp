// ABC353E
struct Trie{
	struct Node{
		map<char,ll> to;
		ll ct;
		Node():ct(0){}
	};
	vector<Node> d;
	Trie():d(1){}

	void add(const string& s){
		ll v=0;
		for(char c:s){
			if(!d.at(v).to.count(c)){
				d.at(v).to[c]=d.size();
				d.pb(Node());
			}
			v=d.at(v).to[c];
		}
		d.at(v).ct++;
	}
	#ifdef DEBUG
	void show(){
		cerr<<"sz:"<<d.size()<<endl;
		ll p=0;
		for(auto e:d){
			cerr<<p++<<" ct:"<<e.ct<<" mp:";
			for(auto m:e.to)cerr<<m<<" ";
			cerr<<endl;
		}
	}
	#endif

	ll ans;
	ll dfs(ll v){
		ll res=d.at(v).ct;
		for(auto p:d.at(v).to){
			res+=dfs(p.se);
		}
		if(v) ans+=res*(res-1)/2;
		return res;
	}

	ll solve(){
		ans=0;
		dfs(0);
		return ans;
	}

};
/*
ll logic(){
	Trie t;
	rep(i,N) t.add(S.at(i));
	t.show();
	ll ans=t.solve();
	return ans;
}
*/
