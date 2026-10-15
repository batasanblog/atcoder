ll extgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;return a;
	}
	ll d=extgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
// ai+bj=g
// https://youtu.be/fDJpXN2R75A?t=6895
ll extgcd(ll a, ll b, ll& i, ll& j) {
  if (b == 0) { i = 1; j = 0; return a;}
  ll p = a/b, g = extgcd(b,a-b*p,j,i);
  j -= p*i;
  return g;
}
/*
	 a<b
	 ax+by=g
	 b%aX+b/a*aX=bX
	 b%aX+aY=g
	 bX-b/a*aX+aY=g
	 a(Y-b/aX)+bX=g
*/
using T=tuple<ll,ll,ll>;
T extgcd(ll a,ll b){
	if(a==0)return {0,1,b};
	auto[X,Y,g]=extgcd(b%a,a);
	return {Y-b/a*X,X,g};
}
