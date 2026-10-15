const size_t MAX_SHOW=26;
template<typename T>
void out(T a){
	if(a>=INF)cerr<<"x";
	else if(a<=-INF)cerr<<"-x";
	else cerr<<a;
}
template<typename T>
void show_base(T a){cerr<<a;}
void show_base(mint a){show_base(a.val());}
void show_base(ll a){out(a);}
void show_base(double a){out(a);}
void show_base(pl a){out(a.fi);cerr<<",";out(a.se);}
template<typename S,typename T,typename U>
void show_base(tuple<S,T,U> t){
	auto [a,b,c]=t;
	show_base(a);
	show_base(",");
	show_base(b);
	show_base(",");
	show_base(c);
}
template<typename T,typename U>
void show_base(map<T,U> mp){
	for(auto [k,v]:mp){
		show_base("(");
		show_base(k);
		show_base(")");
		show_base(v);
	}
}
template<typename T,typename U>
void show_base(unordered_map<T,U> mp){
	for(auto [k,v]:mp){
		show_base("(");
		show_base(k);
		show_base(")");
		show_base(v);
	}
}
template<typename T>
void show_base(set<T> st){
	ll i=0;
	for(auto v:st){
		show_base("(");
		show_base(i++);
		show_base(")");
		show_base(v);
	}
}
template<typename T>
void show_base(unordered_set<T> st){
	ll i=0;
	for(auto v:st){
		show_base("(");
		show_base(i++);
		show_base(")");
		show_base(v);
	}
}
template<typename T>
void show_base(multiset<T> st){
	ll i=0;
	for(auto v:st){
		show_base("(");
		show_base(i++);
		show_base(")");
		show_base(v);
	}
}
template<typename T>
void show_base(deque<T> v){
	rep(i,min(v.size(),MAX_SHOW)){
		show_base("(");
		show_base(i);
		show_base(")");
		show_base(at(v,i));
	}
}
template<typename T>
void show_base(vector<T> v){
	rep(i,min(v.size(),MAX_SHOW)){
		show_base("(");
		show_base(i);
		show_base(")");
		show_base(at(v,i));
	}
}
template<typename T>
void show_base(vector<vector<T>> v){
	ll m=min(v.size(),MAX_SHOW);
	rep(i,m){
		show_base("[");
		show_base(i);
		show_base("]");
		show_base(at(v,i));
		if(i<m-1)show_base('\n');
	}
}
template<typename T>
void show_base(vector<vector<vector<T>>> v){
	ll m=min(v.size(),MAX_SHOW);
	rep(i,m){
		show_base("{");
		show_base(i);
		show_base("}\n");
		show_base(at(v,i));
		if(i<m-1)show_base('\n');
	}
}
void show(){cerr<<"\n";}
template<typename F, typename... R> 
void show(F f,R... r){
	show_base((F)f);
	if(sizeof...(r))show_base(" ");
	show(r...);
}
