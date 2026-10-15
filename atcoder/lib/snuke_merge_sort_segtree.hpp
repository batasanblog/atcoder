// snuke_merge_sort_segtree
struct segtree {
	ll n;
	vector<vector<ll>> a;
	vector<vector<ll>> s;
	segtree(ll mx) {
		n = 1;
		while (n < mx) n <<= 1;
		a.resize(n*2);
		s.resize(n*2, vector<ll>(1));
	}
	void set(ll i, ll x) {
		a[n+i] = {x};
		s[n+i].push_back(x);
	}
	void init() {
		for (ll i = n-1; i >= 1; i--) {
			ll l = i<<1, r = l|1;
			merge(a[l].begin(), a[l].end(),
					a[r].begin(), a[r].end(),
					back_inserter(a[i]));
			s[i] = vector<ll>(a[i].size()+1);
			rep(j,a[i].size()) s[i][j+1] = s[i][j]+a[i][j];
		}
	}

	ll get(ll i, ll x) {
		ll j = upper_bound(a[i].begin(), a[i].end(), x) - a[i].begin();
		return s[i][j];
	}

	ll solve(ll l, ll r, ll x) {
		l += n; r += n;
		ll res = 0;
		while (l < r) {
			if (l&1) res += get(l,x), l++;
			if (r&1) r--, res += get(r,x);
			l >>= 1; r >>= 1;
		}
		return res;
	}
};
/**
int main() {
	int n;
	cin >> n;
	segtree t(n);
	rep(i,n) {
		int a;
		cin >> a;
		t.set(i,a);
	}
	t.init();
**/

