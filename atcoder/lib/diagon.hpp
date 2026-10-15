// Diagonally (Naname) vector.
// Assumption: Column value is set in A.
vector<vl> diagon1(){
	vector<vl> ret(H+W-1);
	ll p = 0;
	rep(i,H){
		ll h = i;
		rep(w,W){
			ret.at(p).pb(A.at(h).at(w));
			if(--h < 0) break;
		}
		++p;
	}
	reps(j,1,W){
		ll w = j;
		for(ll h = H-1; h >= 0; --h){
			ret.at(p).pb(A.at(h).at(w));
			if(++w >= W) break;
		}
		++p;
	}
	return ret;
}
vector<vl> diagon2(){
	vector<vl> ret(H+W-1);
	ll p = 0;
	for(ll i=H-1; i>=0; --i){
		ll h = i;
		rep(w,W){
			ret.at(p).pb(A.at(h).at(w));
			if(++h >= H) break;
		}
		++p;
	}
	reps(j,1,W){
		ll w = j;
		rep(h,H){
			ret.at(p).pb(A.at(h).at(w));
			if(++w >= W) break;
		}
		++p;
	}
	return ret;
}
