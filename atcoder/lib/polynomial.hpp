// (x+a0)(x+a1)(x+a2)...(x+an) 
vector<mint> polynomial(vector<mint> v){
	ll sz = v.size();
	vector<mint> dp(sz+1);dp.at(0)=1;
	rep(i,sz){
		vector<mint> p(sz+1); swap(dp,p);
		rep(j,sz) dp.at(j+1) = p.at(j);
		rep(j,sz) dp.at(j) = dp.at(j) + v.at(i)*p.at(j);
	}
	return dp;
}
/**
int main(){
	modint::set_mod(7);
	ll N; cin>>N;
	vl A(N);
	rep(n,N){
		ll a;cin>>a; A.at(n)=a;
	}
	vector<mint> B(N);
	rep(n,N) B.at(n) = A.at(n);
	auto dp = polynomial(B);
	show("dp",dp);
	vl con(N); con.at(0)=1;
	rep(n,N){
		vl b={A.at(n),1};
		con = convolution_ll(con,b);
	}
	show("convolution",con);
	return 1;
}
**/
