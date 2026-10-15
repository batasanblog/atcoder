// Formal Power Series
using vm = vector<mint>;
struct fps : vm {
	#define d (*this)
	#define s ll(vm::size())
	template<class...Args> fps(Args...args): vm(args...) {}
	fps(initializer_list<mint> a): vm(a.begin(),a.end()) {}
	void rsz(ll n) { if (s < n) resize(n);}
	fps& low_(ll n) { resize(n); return d;}
	fps low(ll n) const { return fps(d).low_(n);}
	mint& operator[](ll i) { rsz(i+1); return vm::operator[](i);}
	mint operator[](ll i) const { return i<s ? vm::operator[](i) : 0;}
	mint operator()(mint x) const {
		mint r;
		for (ll i = s-1; i >= 0; --i) r = r*x+d[i];
		return r;
	}
	fps operator-() const { fps r(d); rep(i,s) r[i] = -r[i]; return r;}
	fps& operator+=(const fps& a) { rsz(a.size()); rep(i,a.size()) d[i] += a[i]; return d;}
	fps& operator-=(const fps& a) { rsz(a.size()); rep(i,a.size()) d[i] -= a[i]; return d;}
	fps& operator*=(const fps& a) { return d = convolution(d, a);}
	fps& operator*=(mint a) { rep(i,s) d[i] *= a; return d;}
	fps& operator/=(mint a) { rep(i,s) d[i] /= a; return d;}
	fps operator+(const fps& a) const { return fps(d) += a;}
	fps operator-(const fps& a) const { return fps(d) -= a;}
	fps operator*(const fps& a) const { return fps(d) *= a;}
	fps operator*(mint a) const { return fps(d) *= a;}
	fps operator/(mint a) const { return fps(d) /= a;}
	fps operator~() const {return inv(s);}
	fps inv(int w) const {
		fps r({d[0].inv()});
		for(ll i=1;i<w;i<<=1)r=r*mint(2)-(r*r*low(i<<1)).low(i<<1);
		return r.low_(w);
	}
	fps& operator/=(const fps&a){ll w=s;d*=~a;return d.low_(w);}
	fps operator/(const fps& a)const{return fps(d)/=a;}
	fps integ() const {
		fps r;
		rep(i,s) r[i+1] = d[i]/(i+1);
		return r;
	}

	fps mod(ll w) const {
		fps r(w);
		rep(i,s) r[i%w] += d[i];
		return r;
	}
	fps pow_rec(ll t,ll n=-1) const {
		if (t == 0) return fps({1});
		fps r = pow_rec(t>>1,n);
		//r = (r*r).mod(s);
		r*=r;
		if(n>=0&&n<s)r.resize(n);
		//if (t&1) r = (r*d).mod(s);
		if(t&1)r*=d;
		if(n>=0&&n<s)r.resize(n);
		return r;
	}
	fps pow(ll t,ll n=-1)const{
		fps res{1},x=d;
		while(t){
			if(t&1){
				res*=x;
				if(n>=0&&n<s)res.resize(n);
			}
			x*=x;
			if(n>=0&&n<s)x.resize(n);
			t>>=1;
		}
		return res;
	}
	mint bostan_mori(fps&Q,ll n){
		if(n==0)return d[0]/Q[0];
		ll sz=Q.size();
		fps P2=d,mQ=Q;
		P2.low_(sz-1);
		for(ll i=1;i<sz;i+=2)mQ[i]=-mQ[i];
		P2*=mQ;
		fps Q2=Q*mQ;
		fps S(sz-1),R(sz);
		rep(i,sz-1)S[i]=(n%2==0)?P2[i*2]:P2[i*2+1];
		rep(i,sz)R[i]=Q2[i*2];
		return S.bostan_mori(R,n>>1);
	}
	#undef s
	#undef d
};
ostream& operator<<(ostream&o,const fps&a) {
	rep(i,a.size()) o<<(i?" ":"")<<a[i].val();
	return o;
}
/**
int main() {
	ll n, m, k, l;
	cin >> n >> m >> k >> l;
	vector<ll> a(k), b(l);
	rep(i,k) cin >> a[i];
	rep(i,l) cin >> b[i];

	ll w = m*2+2;
	fps s(w), x(w);
	rep(i,k) s[a[i]] += 1, s[w-a[i]] += -1;
	x[w-1] = x[0] = x[1] = 1;

	s *= x.pow(n-1);
	s = s.mod(w);

	mint ans;
	rep(i,l) ans += s[b[i]];
	cout << ans.val() << endl;
	return 0;
}
**/
// Formal Power Series
