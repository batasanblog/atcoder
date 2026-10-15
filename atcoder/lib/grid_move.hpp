// Assumption Define H,W,S
//vl vy={-1,0,0,1,-1,-1,1,1};
//vl vx={0,-1,1,0,-1,1,-1,1};
//vector<pl> vp={{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
ll H,W;
vector<string>S;
vector<pl> vp={{-1,0},{0,-1},{0,1},{1,0}};
pl operator-(const pl &x, const pl &y){
	return pl(x.fi-y.fi,x.se-y.se);
}
pl operator-=(pl &x,const pl &y){
	return pl(x.fi-=y.fi,x.se-=y.se);
}
pl operator+(const pl &x,const pl &y){
	return pl(x.fi+y.fi,x.se+y.se);
}
pl operator+=(pl &x,const pl &y){
	return pl(x.fi+=y.fi,x.se+=y.se);
}
// go arround grid
vector<pl> goaround(pl a){
	// if start==goal, do nothing
	vector<pl> ret;
	reps(j,a.se+1,W-a.se)ret.eb(a.fi,j);
	reps(i,a.fi+1,H-a.fi)ret.eb(i,W-1-a.se);
	for(ll j=W-2-a.se;j>=a.se;j--)ret.eb(H-1-a.fi,j);
	for(ll i=H-2-a.fi;i>=a.fi;i--)ret.eb(i,a.se);
	return ret;
}
//
bool in(pl z){
	ll ny=z.fi, nx=z.se;
	if(ny<0 || ny>=H || nx<0 || nx>=W) return false;
	if(S.at(ny).at(nx) == '#') return false;
	return true;
}
vector<pl> next(pl now){
	vector<pl> ret;
	rep(i,vp.size()){
		pl n = now + vp.at(i);
		if(in(n)) ret.pb(n);
	}
	return ret;
}
