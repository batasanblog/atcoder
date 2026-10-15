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
