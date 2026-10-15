template<typename T=mint>
struct fps{
	vector<T> v;
	fps();
	fps(ll s,ll w=0):v(s,w){}
	fps(vector<T>&v):v(v){}
	void rsz(ll n){if(v.size()<n)v.resize(n);}
	fps&low_(ll n){
		v.resize(n);
		return *this;
	}
	fps low(ll n){return fps(v).low_(n);}
	T& operator[](ll i){rsz(i+1);return at(v,i);}
	fps operator-(){
		fps r(v);
		rep(i,v.size())at(r,i)=-at(r,i);
		return r;
	}
	fps&operator-=(fps&a){
		rsz(a.v.size());
		rep(i,a.size())at(v,i)-=at(a,i);
		return *this;
	}
	fps operator-(fps&a){return fps(*this)-=a;}
	fps&operator+=(fps&a){
		rsz(a.size());
		rep(i,a.size())at(v,i)+=at(a,i);
		return *this;
	}
	fps operator+(fps&a){return fps(*this)+=a;}
	fps&operator*=(fps&a){
		ll sz=v.size()-1+a.size()-1+1;
		fps r(sz);
		rep(i,v.size())rep(j,a.size()){
			at(r,i+j)+=at(v,i)*at(a,j);
		}
		swap(*this,r);
		return *this;
	}
	fps operator*(fps&a){return fps(*this)*=a;}
	ll size(){return v.size();}
};
template<typename T=mint>
ostream&operator<<(ostream&o,fps<T>&a){
	rep(i,a.size())o<<at(a.v,i)<<":";
	return o;
}
vector<mint>fps_pow(vector<mint>x,ll n) {
	vector<mint>ret(1,1);
	while(n>0){
		if(n&1)ret=convolution(ret,x);
		x=convolution(x,x);
		n >>= 1; 
	}
	return ret;
}
