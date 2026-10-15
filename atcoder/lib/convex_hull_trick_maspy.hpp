namespace CHT {
template <typename T>
struct Line {
	mutable T k, m, p;
	bool operator<(const Line &o) const { return k < o.k; }
	bool operator<(T x) const { return p < x; }
};

template <typename T>
T lc_inf() {
	return numeric_limits<T>::max();
}
template <>
long double lc_inf<long double>() {
	return 1 / .0;
}

template <typename T>
T lc_div(T a, T b) {
	return a / b - ((a ^ b) < 0 and a % b);
}
template <>
long double lc_div(long double a, long double b) {
	return a / b;
};
template <>
double lc_div(double a, double b) {
	return a / b;
};

template <typename T, bool MINIMIZE = true>
struct LineContainer : multiset<Line<T>, less<>> {
	using super = multiset<Line<T>, less<>>;
	using super::begin, super::end, super::insert, super::erase;
	using super::empty, super::lower_bound;
	T inf = lc_inf<T>();
	bool insect(typename super::iterator x, typename super::iterator y) {
		if (y == end()) return x->p = inf, false;
		if (x->k == y->k)
			x->p = (x->m > y->m ? inf : -inf);
		else
			x->p = lc_div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(T k, T m) {
		if (MINIMIZE) { k = -k, m = -m; }
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (insect(y, z)) z = erase(z);
		if (x != begin() and insect(--x, y)) insect(x, y = erase(y));
		while ((y = x) != begin() and (--x)->p >= y->p) insect(x, erase(y));
	}
	T query(T x) {
		assert(!empty());
		auto l = *lower_bound(x);
		T v = (l.k * x + l.m);
		return (MINIMIZE ? -v : v);
	}
};
}; // namespace CHT

using namespace CHT;
template <typename T>
using CHT_min = LineContainer<T, true>;
template <typename T>
using CHT_max = LineContainer<T, false>;


/*
ll logic(){
	vector<long double> sm(N+1);
	rep(n,N)at(sm,n+1)=at(sm,n)+at(A,n);

	CHT_max<long double> cht;

	
	cout << fixed << setprecision(16);
	vector<long double> ans(N);
	for(ll n=N;n>0;n--){
		cht.add(-n,at(sm,n));
		long double ac=0,wa=INF;
		rep(_,50){
			long double wj=(ac+wa)/2;
			auto x=cht.query(wj);
			if(x>=at(sm,n-1)-wj*(n-1))ac=wj;
			else wa=wj;
		}
		at(ans,n-1)=ac;
	}

	#ifdef DEBUG
	show("sm",sm);
	cerr << "--- Answer ---" << endl;
	#endif
	for(auto a:ans)cout<<a<<'\n';
	return 1;
}
*/
