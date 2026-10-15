#ifdef DEBUG
template <typename T>
void c1(T&w,ll a,const source_location& l){
	ll z1=w.size();
	if(a<0||a>=z1){
		show("out_of_range line",l.line(),"col",l.column(),"func",l.function_name(),a);
		assert(false);
	}
}
#endif
template <typename T>
auto at(T&w,ll a,const source_location& l=source_location::current())->decltype(w.at(a))&{
	#ifdef DEBUG
	c1(w,a,l);
	#endif
	return w.at(a);
}
template <typename T>
auto at(T&w,ll a,ll b,const source_location& l=source_location::current())->decltype(w.at(a).at(b))&{
	return at(w.at(a),b,l);
}
template <typename T>
auto at(T&w,ll a,ll b,ll c,const source_location& l=source_location::current())->decltype(w.at(a).at(b).at(c))&{
	return at(at(w,a,b,l),c,l);
}
template <typename T>
auto at(T&w,ll a,ll b,ll c,ll d,const source_location& l=source_location::current())->decltype(w.at(a).at(b).at(c).at(d))&{
	return at(at(w,a,b,c,l),d,l);
}
