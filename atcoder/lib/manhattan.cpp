// Manhattan.cpp
// Assume H,W defined.
// ll H,W;
vp manhattan(ll y,ll x,ll d){
	vl dy={1,-1,-1,1};
	vl dx={1,1,-1,-1};
	x -= d;
	vp ret;
	rep(i,4)rep(j,d){
		y += dy.at(i);
		x += dx.at(i);
		if(y >= 0 && y < H && x >= 0 && x < W) ret.eb(y,x);
	}
	return ret;
}
// End Manhattan.cpp
