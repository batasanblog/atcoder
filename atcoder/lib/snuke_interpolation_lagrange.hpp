// Ragrange Interpolation (Hokan)
struct Interpolation {
	ll n;
	vector<mint> a;
	Interpolation() {}
	Interpolation(const vector<mint>& p) {
		n = p.size();
		a.resize(n);
		vector<mint> invf(n,1);
		mint f = 1;
		for (ll i = 1; i < n; ++i) f *= i;
		invf[n-1] = mint(1)/f;
		for (ll i = n-1; i >= 1; --i) invf[i-1] = invf[i]*i;
		for (ll i = 0; i < n; ++i) {
			mint b = invf[i] * invf[n-1-i];
			a[i] = p[i] * ((n-1-i)%2 == 1 ? -b : b);
		}
	}
	mint operator()(mint x) const {
		vector<mint> r(n,1);
		for (ll i = n-1; i >= 1; --i) r[i-1] = r[i]*(x-i);
		mint l = 1, res;
		for (ll i = 0; i < n; ++i) {
			res += a[i]*l*r[i];
			l *= x-i;
		}
		return res;
	}
};
// Lagrange
