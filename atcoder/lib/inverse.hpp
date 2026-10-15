/*
	 inverse by O(N)
	 MOD/x*x+MOD%x=MOD
	 MOD/x*x=-MOD%x
	 MOD/x/-inv(MOD%x)=inv(x);
	 MOD%x<x then caliculate O(N)
	 */
const ll MOD=998244353;
vl inverse(ll n){
	vl ret(n+1);
	at(ret,1)=1;
	reps(i,2,n+1){
		at(ret,i)=MOD/i*-at(ret,MOD%i);
		at(ret,i)=(at(ret,i)%MOD+MOD)%MOD;
	}
	return ret;
}
