ll floor_sqrt(ll x){
	ll ac=1,wa=x+1;
	while(ac+1<wa){
		ll wj=(ac+wa)/2;
		if(__int128(wj)*wj>x)wa=wj;
		else ac=wj;
	#ifdef DEBUG0
		show(ac,wa,wj,wj*wj);
	#endif
	}
	return ac;
}
