// Weighted Union find
struct union_find_w {
	ll ans=0;
	vl d,w;
	//vl c;
	//vector<bool> on;
	union_find_w(){}
	union_find_w(ll mx):d(mx,-1),w(mx,0){}
	ll leader(ll x) {
		assert(0<=x&&x<at(d));
		if(d[x]<0) return x;
		auto r=leader(d[x]);
		w[x]+=w[d[x]];
		return d[x] = r;
	}
	ll weight(ll x){
		leader(x);return w[x];
	}
	ll diff(ll x,ll y){
		return weight(x)-weight(y);
	}
	bool merge(ll x,ll y,ll r=0) {
		r+=weight(x);r-=weight(y);
		x=leader(x);y=leader(y);
		if(x==y) return false;
		if(d[x]>d[y]){
			swap(x,y);
			r=-r;
		}
		d[x]+=d[y];d[y]=x;
		w[y]=r;
		// common attribute
		//if(on[x]&&!on[y])ans+=c[y];
		//if(!on[x]&&on[y])ans+=c[x];
		// vertex attribute
		//c[x]+=c[y];
		//on[x]=on[x]|on[y];
		return true;
	}
	bool same(ll x,ll y) {return leader(x)==leader(y);}
	ll size(ll x) {return -d[leader(x)];}
	ll operator[](ll x) {return leader(x);}
	ll operator()(ll x) {return size(x);}
	bool operator()(ll x,ll y){
		return merge(x,y);
	}
};
