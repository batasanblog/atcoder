// Matrix Pow
using vvm = vector<vector<mint>>;
vvm matrix_mul(vvm a, vvm b){
	assert(a.size() > 0 && a.at(0).size() > 0);
	assert(b.size() > 0 && b.at(0).size() > 0);
	assert(a.at(0).size() == b.size());
	ll s = b.size(), sx = b.at(0).size(), sy = a.size();
	vvm r(sy,vector<mint>(sx,0));
	rep(i,sy)rep(j,sx)rep(k,s){
		r.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j);
	}
	return r;
}
vvm matrix_pow(vvm a,ll n){
	assert(a.size() > 0 && a.at(0).size() > 0);
	assert(a.size() == a.at(0).size());
	ll s = a.size();
	vvm r = vector(s,vector<mint>(s,0));
	rep(i,s) r.at(i).at(i) = 1;
	while(n){
		if(n & 1) r = matrix_mul(r,a);
		a = matrix_mul(a,a);
		n >>= 1;
	}
	return r;
}
vector<vl> matrix_mul(vector<vl> a, vector<vl> b){
	assert(a.size() > 0 && a.at(0).size() > 0);
	assert(b.size() > 0 && b.at(0).size() > 0);
	assert(a.at(0).size() == b.size());
	ll s = b.size(), sx = b.at(0).size(), sy = a.size();
	vector r(sy,vl(sx,0));
	rep(i,sy)rep(j,sx)rep(k,s){
		r.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j);
	}
	return r;
}
vector<vl> matrix_pow(vector<vl> a,ll n){
	assert(a.size() > 0 && a.at(0).size() > 0);
	assert(a.size() == a.at(0).size());
	ll s = a.size();
	vector r = vector(s,vl(s,0));
	rep(i,s) r.at(i).at(i) = 1LL;
	while(n){
		if(n & 1LL) r = matrix_mul(r,a);
		a = matrix_mul(a,a);
		n >>= 1LL;
	}
	return r;
}
// Matrix Pow
