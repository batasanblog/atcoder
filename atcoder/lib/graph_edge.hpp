// Graph Edge
struct edge{
	ll v,c;
	edge(ll a,ll b):v(a),c(b){}
};
#ifdef DEBUG
ostream &operator<<(ostream &o,const edge &e){
	o<<e.v<<","<<e.c; return o;
}
#endif
// Graph Edge
