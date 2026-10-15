struct union_find{
	vl d; //Size for root, root for others
	vl a; //Leader Atrributes
	ll get(ll x){return a[leader(x)];}
	union_find(){}
	union_find(ll mx):d(mx,-1),a(mx,0){
		rep(i,mx)at(a,i)=i;
	}
	ll leader(ll x) {
		assert(0<=x&&x<at(d));
		if(d[x]<0) return x;
		auto r=leader(d[x]);
		return d[x] = r;
	}
	bool merge(ll x,ll y,ll t=0) {
		x=leader(x);y=leader(y);
		if(x==y) return false;
		if(d[x]>d[y])swap(x,y);
		d[x]+=d[y];d[y]=x;
		// common attribute
		// Leader attribute
		a[x]=t;
		return true;
	}
	vector<vl>groups(){
		map<ll,vl>mp;
		rep(x,d.size())mp[leader(x)].pb(x);
		vector<vl> r;
		for(auto&[_,v]:mp)r.pb(v);
		return r;
	}
	bool same(ll x,ll y) {return leader(x)==leader(y);}
	ll size(ll x) {return -d[leader(x)];}
	ll operator[](ll x) {return leader(x);}
	ll operator()(ll x) {return size(x);}
	bool operator()(ll x,ll y){
		return merge(x,y);
	}
};
