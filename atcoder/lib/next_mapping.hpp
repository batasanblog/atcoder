// r-keta n-shinsu  start next_mapping
template <class BidirectionalIterator, class T>
bool next_mapping ( BidirectionalIterator first ,
	BidirectionalIterator last ,
	T first_value , T last_value ) {
	if ( last == first ) {
		return false ;
	}
	do {
		if (++(*( -- last )) != last_value ) {
			return true ;
		}
		* last = first_value ;
	} while ( last != first );
	return false ;
}
// end next_mapping
/**
int main(){
	ll N,R;cin>>N>>R;
	vl v(R);
	do{
		show(v);
	}while(next_mapping(v.begin(),v.end(),0LL,N));
}
**/
