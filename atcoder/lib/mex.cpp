ll mex(vl v){
	ll tmp = 0,ret = 0;
	for(auto e:v){
		tmp |= 1LL<<e;
	}
	while(tmp>>ret & 1LL) ++ret;
	return ret;
}
