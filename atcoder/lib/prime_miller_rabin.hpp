// MillerRabinTest
bool is_prime(ll num){
	if(num<=1)return false;
	if(num==2)return true;
	if(num>2&&(num&1)==0)return false;

	ll d=num-1;
	while(!(d&1))d>>=1;

	auto modpow=[](ll base,ll exp,ll mod)->ll{
		ll result=1;
		base%=mod;
		while(exp>0){
			if(exp&1)result=(__int128(result)*base)%mod;
			base=(__int128(base)*base)%mod;
			exp>>=1;
		}
		return result;
	};

	random_device rd;
	mt19937_64 gen(rd());
	rep(_,20){ // 20:seido
		uniform_int_distribution<ll>dist(1,num-1);
		ll a=dist(gen);
		ll t=d;
		ll y=modpow(a,t,num);
		while(t!=num-1&&y!=1&&y!=num-1){
			y=(__int128(y)*y)%num;
			t<<=1;
		}
		if(y!=num-1&&!(t&1))return false;
	}
	return true;
}

// 素因数分解（Pollard's Rho 法 + 試し割り）
vl prime_fact(ll n){
	vector<ll>ret;
	for(int i=2;i<100;++i){
		while(n%i==0){
			ret.push_back(i);
			n/=i;
		}
	}
	if(n==1)return ret;
	vector<ll>calc={n};
	mt19937_64 rng(random_device{}());
	while(!calc.empty()){
		n=calc.back();calc.pop_back();
		while(!is_prime(n)){
			ll x=rng()%n;
			ll plus=rng()%(n-1)+1;
			ll y=x;
			while(true){
				x=((__int128)x*x+plus)%n;
				y=((__int128)y*y+plus)%n;
				y=((__int128)y*y+plus)%n;
				ll d=gcd(abs(x-y),n);
				if(d==1)continue;
				if(d==n||d==0)break;
				if(is_prime(d))ret.push_back(d);
				else calc.push_back(d);
				n/=d;
				break;
			}
		}
		ret.push_back(n);
	}
	return ret;
}
