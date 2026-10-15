vl pr(N);
rep(n,N)at(pr,n)=n;
auto leader=[&](ll x){
	auto rec=[&](auto f,ll _x){
		if(_x==at(pr,_x))return _x;
		return at(pr,_x)=f(f,at(pr,_x));
	};
	return rec(rec,x);
};
