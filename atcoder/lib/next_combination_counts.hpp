// partial number , bunkatsusu
template < class BidirectionalIterator >
	bool next_combination_counts ( 
			BidirectionalIterator first 
			, BidirectionalIterator last ) {
	BidirectionalIterator current = last ;
	while ( current != first && *( -- current ) == 0) {
	}
	if ( current == first ) {
		if ( first != last && * first != 0)
		std :: iter_swap ( -- last , first );
		return false ;
	}
	--(* current );
	std :: iter_swap ( -- last , current );
	++(*( --current ));
	return true ;
}
/**
int main(){
	ll N,R;cin>>N>>R;
	vl v(N);
	v.back()=R;
	do{
		show(v);
	}while(next_combination_counts(v.begin(),v.end()));
	return 0;
}
*/
