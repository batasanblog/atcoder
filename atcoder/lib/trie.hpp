//ABC403E
struct Trie{
	struct Node{
		map<char,ll> to;
		ll ct,q;
		Node():ct(0),q(Q){}
		Node(ll _q):ct(0),q(_q){}
	};
	vector<Node> d;
	Trie():d(1){}

	void add(const string&s,ll q){
		ll v=0;
		//for(char c:s){
		rep(i,s.size()){
			char c=at(s,i);
			if(!at(d,v).to.count(c)){
				at(d,v).to[c]=d.size();
				if(i==(ll)s.size()-1)d.pb(Node(q));
				else d.pb(Node());
			}
			v=at(d,v).to[c];
		}
		at(d,v).ct++;
	}
	ll query(const string&s){
		ll v=0,ret=Q;
		//for(char c:s){
		rep(i,s.size()){
			char c=at(s,i);
			if(!at(d,v).to.count(c)){
				return ret;
			}
			v=at(d,v).to[c];
			ret=min(ret,at(d,v).q);
		}
		at(d,v).ct++;
		return ret;
	}
	#ifdef DEBUG
	void show(){
		cerr<<"sz:"<<d.size()<<endl;
		ll p=0;
		for(auto e:d){
			cerr<<p++<<" ct:"<<e.ct<<" mp:";
			for(auto [k,v]:e.to)cerr<<k<<":"<<v<<" ";
			cerr<<endl;
		}
	}
	#endif

	ll ans;
	ll dfs(ll v){
		ll res=at(d,v).ct;
		for(auto p:at(d,v).to){
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
	vl imos(Q+1);
	for(auto[s,q]:X){
		t.add(s,q);
	}
	for(auto[s,q]:Y){
		auto r=t.query(s);
		if(q<r){
			at(imos,q)++;
			at(imos,r)--;
		}
	}
	#ifdef DEBUG
	show("imos",imos);
	cerr << "--- Answer ---" << endl;
	#endif
	rep(qi,Q)at(imos,qi+1)+=at(imos,qi);
	rep(qi,Q)cout<<at(imos,qi)<<'\n';
	return 1;
}
*/
