ll _gcd(ll a,ll b){
	if(!b)return a;
	return _gcd(b,a%b);
}
template<typename... A>
ll _gcd(ll a, A... args){
	return _gcd(a, _gcd(args...));
}
ll _gcd(vl v){
	return accumulate(be(v),0,[](ll a,ll b){return gcd(a,b);});
}
