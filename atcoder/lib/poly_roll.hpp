// Grid Roll 2/PAI(90degree)
// base(now) + e (relatively distance)
// Assumption  Define H,W
vl vr={0,-1,1,0};
vector<pl> roll(pl now,pl e){
	vector<pl> ret;
	rep(i,4){
		ll ny = now.fi + e.fi;
		ll nx = now.se + e.se;
		if(ny>=0 && ny<H && nx>=0 && nx<W){
			ret.eb(ny,nx);
		}
		ll x = e.se*vr.at(0) + e.fi*vr.at(1);
		ll y = e.se*vr.at(2) + e.fi*vr.at(3);
		e.se = x; e.fi = y;
	}
	return ret;
}
// Grid Roll
