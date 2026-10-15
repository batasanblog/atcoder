
// エラトステネスの篩
struct Eratosthenes {
	vector<bool> isprime;
	vector<ll> minfactor;
	Eratosthenes(ll N) : isprime(N+1, true),
							minfactor(N+1, -1) {
		isprime[1] = false;
		minfactor[1] = 1;
		for (ll p = 2; p <= N; ++p) {
			if (!isprime[p]) continue;
			minfactor[p] = p;
			for (ll q = p * 2; q <= N; q += p) {
				isprime[q] = false;
				if (minfactor[q] == -1) minfactor[q] = p;
			}
		}
	}
	vector<pair<ll,ll>> factorize(ll n) {
		vector<pair<ll,ll>> res;
		while (n > 1) {
			ll p = minfactor[n];
			ll exp = 0;
			while (minfactor[n] == p) {
				n /= p;
				++exp;
			}
			res.emplace_back(p, exp);
		}
		return res;
	}
	// 高速約数列挙
	vector<ll> divisors(ll n) {
		vector<ll> res({1});
		auto pf = factorize(n);
		for (auto p : pf) {
			ll s = (ll)res.size();
			for (ll i = 0; i < s; ++i) {
				ll v = 1;
				for (ll j = 0; j < p.second; ++j) {
					v *= p.first;
					res.push_back(res[i] * v);
				}
			}
		}
		return res;
	}
};
