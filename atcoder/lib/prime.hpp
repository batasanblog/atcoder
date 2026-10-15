// 原子根、素数判定
random_device rd;
mt19937_64 gen(rd());
ll random(ll l,ll h){
	uniform_int_distribution<ll> dist(l,h);
	return dist(gen);
}
ll modpow(ll x,ll n,ll m){
	x%=m;
	ll ret=1;
	while(n>0){
		if(n&1) ret=__int128(ret)*x%m;
		x=__int128(x)*x%m;
		n>>=1; 
	}
	return ret;
}
// MillerRabinTest
bool is_prime(ll num){
	if(num<=1)return false;
	if(num==2)return true;
	if(num>2&&(num&1)==0)return false;

	ll d=num-1;
	while(!(d&1))d>>=1;

	//random_device rd;
	//mt19937_64 gen(rd());
	rep(_,20){ // 20:seido
		//uniform_int_distribution<ll>dist(1,num-1);
		//ll a=dist(gen);
		ll a=random(1,num-1);
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
	//mt19937_64 rng(random_device{}());
	while(!calc.empty()){
		n=calc.back();calc.pop_back();
		while(!is_prime(n)){
			//ll x=rng()%n;
			ll x=random(1,n-1);
			//ll plus=rng()%(n-1)+1;
			ll plus=random(1,n-1);
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
ll primitive_root(ll a){
	show("primitive_root",a);
	assert(is_prime(a));
	if(a==2)return 1ll;
	auto pf=prime_fact(a-1);
	pf.erase(unique(be(pf)),pf.end());
	show("a",a,"pf",pf);
	while(true){
		ll r=random(2,a-1);
		bool ok=true;
		for(auto f:pf){
			if(modpow(r,(a-1)/f,a)==1){
				ok=false;break;
			}
		}
		if(ok)return r;
	}
	return -1ll;
}
// list up prime factors , Soinsu Bunkai, Yakusu
map<ll,ll> prime_factor_map(ll n){
	map<ll,ll> ret;
	for(ll i=2;i*i<=n;++i){
		ll tmp=0;
		while(n%i==0){
			++tmp;
			n /= i;
		}
		if(tmp>0)ret[i]=tmp;
	}
	if(n!=1)ret[n]=1;
	return ret;
}
vector<pl> prime_factor_pair(ll n){
	vector<pl> ret;
	for(ll i=2;i*i<=n;++i){
		ll tmp=0;
		while(n%i==0){
			++tmp;
			n /= i;
		}
		if(tmp>0)ret.eb(i,tmp);
	}
	if(n!=1)ret.eb(n,1);
	return ret;
}
// List up divisors
//vl divisors(map<ll,ll> mp){
//void divisors(ll now, ll ind, map<ll,ll> &m, vl &ret){
void divisors(ll now,ll ind,vector<pl>&m,vl&ret){
	if(ind==ll(m.size())){
		ret.pb(now); return;
	}
	ll p=1;
	auto it=m.begin()+ind;
	rep(i,it->se+1){
		divisors(now*p,ind+1,m,ret);
		p*=it->fi;
	}
}
/**
int main(){
	auto pf = prime_factor_pair(N);
	vl divs;
	divisors(1, 0, pf, divs);
**/
// End of prime_number.hpp
