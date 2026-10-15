#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint=static_modint<998244353>;
//using mint = modint;
//using mint=static_modint<1000000007>;
using ll=long long;
using ull=unsigned long long;
using pl=pair<ll,ll>;
using vl=vector<ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);++i)
#define reps(i,s,n) for(ll i=(s);i<(ll)(n);++i)
#define rep1(i,n) for(ll i=1;i<=(ll)(n);++i)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define be(v) (v).begin(),(v).end()
const ll INF=4e18;
template<typename T>inline ll at(T&w){return w.size();}
#ifdef DEBUG
template<typename T>
void check_range(T&w,auto&&a,const source_location& l){
	if(a<0||a>=at(w)){
		cerr<<"OORange! line "<<l.line()<<" col "<<l.column()<<" index "<<a<<" size "<<w.size()<<" func "<<l.function_name()<<endl;
		assert(false);
	}
}
template<typename T>
decltype(auto)at(T&w,auto&&a,const source_location&l=source_location::current()){
	check_range(w,a,l); // if slower, delete it.
	return w[a];
}
template<typename T>
decltype(auto)at(T&w,auto&&a,auto&&b,const source_location&l=source_location::current()){
	return at(at(w,a,l),b,l);
}
template<typename T>
decltype(auto)at(T&w,auto&&a,auto&&b,auto&&c,const source_location&l=source_location::current()){
	return at(at(w,a,b,l),c,l);
}
template<typename T>
decltype(auto)at(T&w,auto&&a,auto&&b,auto&&c,auto&&d,const source_location&l=source_location::current()){
	return at(at(w,a,b,c,l),d,l);
}
template<typename T>
decltype(auto)at(T&w,pl a,const source_location&l=source_location::current()){
	return at(w,a.fi,a.se,l);
}
#else
template<typename T>inline decltype(auto)at(T&w,auto&&a){return w[a];}
template<typename T>inline decltype(auto)at(T&w,auto&&a,auto&&b){return w[a][b];}
template<typename T>inline decltype(auto)at(T&w,auto&&a,auto&&b,auto&&c){return w[a][b][c];}
template<typename T>inline decltype(auto)at(T&w,auto&&a,auto&&b,auto&&c,auto&&d){return w[a][b][c][d];}
template<typename T>inline decltype(auto)at(T&w,pl a){return w[a.fi][a.se];}
#endif
#ifdef DEBUG
#include <debug.hpp>
#else
#define show(...)
#endif

auto logic(){
	ll N;
	cin>>N;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t=1;
	//cin>>t;
	rep(i,t)logic();
	//string a;rep(i,t)logic()?a+="Yes\n":a+="No\n";cout<<a;
	//string a;rep(i,t){a+=to_string(logic())+"\n";}cout<<a;
	//string a;rep(i,t){a+=logic();}cout<<a;
	return 0;
}
//cout << fixed << setprecision(15);

