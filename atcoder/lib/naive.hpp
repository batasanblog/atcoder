#ifdef DEBUG
random_device rd;
mt19937 gen(rd());
ll random(ll l,ll h){
	uniform_int_distribution<ll> dist(l,h);
	return dist(gen);
}
ll naive(){
	return 1;
}
void random_test(){
	rep(q,100){
		N=random(1LL,1000LL);
		showall();
		ll lans=logic(),nans=naive();
		if(lans!=nans){ show(" WA",lans,nans); break; }
		else{ show(" AC",lans,nans); }
	}
}
//show("naive=",naive());
//random_test();
#endif

