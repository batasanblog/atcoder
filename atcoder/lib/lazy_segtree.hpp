//lazy_segtree rsq+raq sum+add
//vector<pl>init(N,pl(0,1));
//lazy_segtree<pl,op,ee,ll,ma,co,id>seg(init);
pl op(pl a,pl b){return {a.fi+b.fi,a.se+b.se};}
pl ee(){return {0,0};}
pl ma(ll f,pl a){return {a.fi+f*a.se,a.se};}
ll co(ll f,ll g){return f+g;}
ll id(){return 0;}
//lazy_segtree rmq+raq max+add  (min)
//lazy_segtree<ll,op,ee,ll,ma,co,id>seg(N);
ll op(ll a,ll b){return max(a,b);} // min(a,b)
ll ee(){return -INF;} // INF
ll ma(ll f,ll a){return f+a;}
ll co(ll f,ll g){return f+g;}
ll id(){return 0;}
//lazy_segtree rmq+ruq max+update  (min)
//lazy_segtree<ll,op,ee,ll,ma,co,id>seg(N);
ll op(ll a,ll b){return max(a,b);} // min(a,b)
ll ee(){return -INF;} // INF
ll ma(ll f,ll a){return f==INF?a:f;}
ll co(ll f,ll g){return f==INF?g:f;}
ll id(){return INF;}
// lazy_segtree rsq+ruq sum+update
//vector<pl>init(N,pl(0,1));
//lazy_segtree<pl,op,ee,ll,ma,co,id>seg(init);
pl op(pl a,pl b){return {a.fi+b.fi,a.se+b.se};}
pl ee(){return {0,0};}
//pl ma(ll f,pl a){return f==INF?a:{f*a.se,a.se};}
pl ma(ll f,pl a){return f==INF?a:pl(f*a.se,a.se);}
ll co(ll f,ll g){return f==INF?g:f;}
ll id(){return INF;}
/**
int main(){
	vector<pl> v(N,{0,1});
	//vl v(N);
	lazy_segtree<pl,op,ee,ll,ma,co,id>seg(v);
}
**/
// "lazy_segtree min/max/sum,add/upd"
using G=tuple<ll,ll,pl>;
bool add=false; // only at first
ll ID(){return add?0:INF;}
G op(G a,G b){
	auto [p,q,r]=a;
	auto [s,t,u]=b;
	return G(min(p,s),max(q,t),pl(r.fi+u.fi,r.se+u.se));
}
G ee(){return G(INF,-INF,pl(0,1));}
G ma(ll f,G a){
	auto [p,q,r]=a;
	if(add){
		return G(f+p,f+q,pl(r.fi+f*r.se,r.se));
	}
	if(f==ID())return a;
	return G(f,f,pl(f*r.se,r.se));
}
ll co(ll f,ll g){
	if(add)return f+g;
	return f==ID()?g:f;
}
ll id(){return ID();}
ll value;
bool right(G v){
	auto&[n,x,s]=v;
	return s.fi<=value; // change here
}
bool left(G v){
	auto&[n,x,s]=v;
	return s.fi<=value; // change here
}
/*
{
	vector<G>v(N,ee());
	//rep(n,N)get<0>(at(v,n))=at(A,n);
	rep(n,N){
		auto&[mn,mx,sm]=at(v,n);
		mn=mx=sm.fi=at(A,n);
	}
	lazy_segtree<G,op,ee,ll,ma,co,id> seg(v);
	auto put=[&](ll&&p,ll&&v){
		G g(ee()); get<1>(g)=v;
		seg.set(p,g);
	};
	auto val=[&](ll&&p){
		return get<1>(seg.get(p));
	};
	auto prod=[&](ll&&l,ll&&r){
		return get<1>(seg.prod(l,r));
	};

#ifdef DEBUG
	value=v;
	show("r",l,v,seg.max_right<right>(l));
	show("l",r,v,seg.min_left<left>(r));
#endif
}
*/
// end of lazy_segtree
