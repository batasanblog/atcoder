unsigned int bit_ceil(unsigned int n) {
	unsigned int x = 1;
	while (x < (unsigned int)(n)) x *= 2;
	return x;
}
int countr_zero(unsigned int n) {
	return __builtin_ctz(n);
}
template <class S, auto op, auto e> struct segki {
	static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
			"op must work as S(S, S)");
	static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
			"e must work as S()");

	public:
	segki() : segki(0) {}
	explicit segki(int n) : segki(std::vector<S>(n, e())) {}
	explicit segki(const std::vector<S>& v) : _n(int(v.size())) {
		size = (int)bit_ceil((unsigned int)(_n));
		log = countr_zero((unsigned int)size);
		d = std::vector<S>(2 * size, e());
		for (int i = 0; i < _n; i++) d[size + i] = v[i];
		for (int i = size - 1; i >= 1; i--) {
			update(i);
		}
	}

	void set(int p, S x) {
		assert(0 <= p && p < _n);
		p += size;
		d[p] = x;
		for (int i = 1; i <= log; i++) update(p >> i);
	}

	S get(int p) const {
		assert(0 <= p && p < _n);
		return d[p + size];
	}

	S prod(int l, int r) const {
		assert(0 <= l && l <= r && r <= _n);
		S sml = e(), smr = e();
		l += size;
		r += size;

		while (l < r) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}
		return op(sml, smr);
	}

	ll sum2(int a,int b,ll v) const {
		return sum2_sub(a,b,v,0,size,1);
	}
	ll sum2_sub(int a,int b,ll v,ll l,ll r,ll k) const {
		assert(0 <= a && a <= b && b <= _n);

		if(r<=a || b<=l){
			return 0;
		}else if(a<=l && r<=b){
			auto ret=upper_bound(be(d[k]),v)-d[k].begin();
			return ret;
		}
		return sum2_sub(a,b,v,l,(l+r)/2,k*2)
			+sum2_sub(a,b,v,(l+r)/2,r,k*2+1);
	}

	ll sum(int l, int r,ll v) const {
		assert(0 <= l && l <= r && r <= _n);
		ll sml = 0, smr = 0;
		l += size;
		r += size;

		auto f=[&](S s){
			return upper_bound(be(s),v)-s.begin();
		};

		while (l < r) {
			if (l & 1) sml +=f(d[l++]);
			if (r & 1) smr +=f(d[--r]);
			l >>= 1;
			r >>= 1;
		}

		return sml+smr;
	}

	S all_prod() const { return d[1]; }

	template <bool (*f)(S)> int max_right(int l) const {
		return max_right(l, [](S x) { return f(x); });
	}
	template <class F> int max_right(int l, F f) const {
		assert(0 <= l && l <= _n);
		assert(f(e()));
		if (l == _n) return _n;
		l += size;
		S sm = e();
		do {
			while (l % 2 == 0) l >>= 1;
			if (!f(op(sm, d[l]))) {
				while (l < size) {
					l = (2 * l);
					if (f(op(sm, d[l]))) {
						sm = op(sm, d[l]);
						l++;
					}
				}
				return l - size;
			}
			sm = op(sm, d[l]);
			l++;
		} while ((l & -l) != l);
		return _n;
	}

	template <bool (*f)(S)> int min_left(int r) const {
		return min_left(r, [](S x) { return f(x); });
	}
	template <class F> int min_left(int r, F f) const {
		assert(0 <= r && r <= _n);
		assert(f(e()));
		if (r == 0) return 0;
		r += size;
		S sm = e();
		do {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!f(op(d[r], sm))) {
				while (r < size) {
					r = (2 * r + 1);
					if (f(op(d[r], sm))) {
						sm = op(d[r], sm);
						r--;
					}
				}
				return r + 1 - size;
			}
			sm = op(d[r], sm);
		} while ((r & -r) != r);
		return 0;
	}

	void print(){
		rep(i,d.size()){
			cerr<<i<<":"<<d[i]<<" ";
		}
		cerr<<endl;
	}

	private:
	int _n, size, log;
	std::vector<S> d;

	void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
/**
	vl op(vl a,vl b){
	vl c;
	merge(be(a),be(b),back_inserter(c));
	return c;
	}
	vl se(){return vl();}
	ll logic(){
	segki<vl,op,se> seg(w);
	}
 **/
