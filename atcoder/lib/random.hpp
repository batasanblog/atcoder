random_device rd;
mt19937_64 gen(rd());
ll random(ll l,ll h){
	uniform_int_distribution<ll> dist(l,h);
	return dist(gen);
}
//mt19937_64 rng(random_device{}());
/**
bool solve(){
	#ifdef DEBUG
	//rep(i,100)show(random(1,100),'\n');
	cerr << "--- Input ---" << endl;
	#endif
**/
