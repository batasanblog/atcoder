// Iterative Square Method / Kurikaeshi 2 jo ho
const ll MOD=1000000007;
ll mpow(ll x,ll n){
	ll ret=1LL;
	while(n>0LL){
		if(1LL & n)ret = ret*x%MOD;
		x = x*x%MOD;
		n >>= 1LL;
	}
	return ret;
}
// Iterative Square Method / Kurikaeshi 2 jo ho

