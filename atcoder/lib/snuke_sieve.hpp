// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
	ll n;
	vector<ll> f, primes;
	Sieve(ll n=1):n(n), f(n+1) {
		f[0] = f[1] = -1;
		for (ll i = 2; i <= n; ++i) {
			if (f[i]) continue;
			primes.push_back(i);
			f[i] = i;
			for (ll j = i*i; j <= n; j += i) {
				if (!f[j]) f[j] = i;
			}
		}
	}

	bool isPrime(ll x) { return f[x] == x;}

	vector<ll> factorList(ll x) {
		vector<ll> res;
		while (x != 1) {
			res.push_back(f[x]);
			x /= f[x];
		}
		return res;
	}
	vector<pl> factor(ll x) {
		vector<ll> fl = factorList(x);
		if (fl.size() == 0) return {};
		vector<pl> res(1, pl(fl[0], 0));
		for (ll p : fl) {
			if (res.back().first == p) {
				res.back().second++;
			} else {
				res.emplace_back(p, 1);
			}
		}
		return res;
	}
	vector<pl> factor2(ll x) {
		vector<pl> res;
		for (ll p : primes) {
			ll y = 0;
			while (x%p == 0) x /= p, ++y;
			if (y != 0) res.emplace_back(p,y);
		}
		if (x != 1) res.emplace_back(x,1);
		return res;
	}
	// Only prime factors combination
	vl divs(ll x){
		vl ret(1,1);
		for(auto [e,_]:factor(x)){
			for(ll i=ret.size()-1;i>=0;--i){
				ret.pb(e*ret.at(i));
			}
		}
		ret.erase(ret.begin());
		return ret;
	}
};
//} sieve(MX);
/*
	 ll logic(){
	 rep(n,N){
	 pf.at(n)=sieve.factor(A.at(n));
	 }
	 }
 */
