// Union find
struct uf {
	vl d;
	uf(){}
	uf(ll mx):d(mx,-1){}
	ll root(ll x) {
		if(d[x] < 0) return x;
		return d[x] = root(d[x]);
	}
	bool unite(ll x, ll y) {
		x = root(x); y = root(y);
		if(x == y) return false;
		if(d[x] > d[y]) swap(x,y);
		d[x] += d[y]; d[y] = x;
		return true;
	}
	bool same(ll x, ll y) { return root(x) == root(y);}
	ll size(ll x) { return -d[root(x)];}
	ll operator[](ll x) { return root(x);}
	ll operator()(ll x) { return size(x);}
};
//
