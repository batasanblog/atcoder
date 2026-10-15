template<typename T=mint>
T bostan_mori(fps<T>&P,fps<T>&Q,ll n){
	if(n==0)return at(P,0)/at(Q,0);
	ll sz=Q.size();
	fps P2=P,mQ=Q;
	P2.low_(sz-1);
	for(ll i=1;i<sz;i+=2)at(mQ,i)=-at(mQ,i);
	P2*=mQ;
	fps Q2=Q*mQ;
	fps S(sz-1),R(sz);
	rep(i,sz-1)at(S,i)=(n%2==0)?at(P2,i*2):at(P2,i*2+1);
	rep(i,sz)at(R,i)=at(Q2,i*2);
	return bostan_mori(S,R,n>>1);
}
