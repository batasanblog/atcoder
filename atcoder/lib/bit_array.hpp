auto f=[&](ll s,ll a){
	return (s>>a*2)&3;
};
auto g=[&](ll s,ll a,ll b){
	s&=~(3ll<<a*2);
	s|=b<<a*2;
	return s;
};
