// Polyomio Roll 2/PAI(90degree)
// vector<pl> (relatively distance)
// Assumption  Define H,W
// set relative postions
//ll H,W;
vector<pl> set_poly(vector<string> vs){
	vector<pl> ret;
	bool on=false; pl s;
	rep(i,H)rep(j,W){
		if(!on && vs.at(i).at(j) == '#'){
			on = true; s = pl(i,j);
		}
		if(on && vs.at(i).at(j) == '#'){
			ret.eb(i-s.fi, j-s.se);
		}
	}
	return ret;
}
// rotate relative positions
vl vr={0,-1,1,0}; // rotate right 90 degree
//vl vr={0,1,-1,0}; // rotate left
//vl vr={-1,0,0,-1}; // rotate 180 degree
void rotate_poly(vector<pl> &poly){
	vector<pl> ret;
	for(auto e:poly){
		ll x = e.se*vr.at(0) + e.fi*vr.at(1);
		ll y = e.se*vr.at(2) + e.fi*vr.at(3);
		ret.eb(y,x);
	}
	swap(ret,poly);
}
// set real positions
vector<pl> get_poly(pl now, vector<pl> &poly){
	vector<pl> ret;
	for(auto e:poly){
		ll y = now.fi + e.fi;
		ll x = now.se + e.se;
		ret.eb(y,x);
	}
	return ret;
}
// check
bool check_poly(vector<pl> &p){ // p: real positions
	for(auto e:p){
		if(e.fi<0 || e.fi>=H || e.se<0 || e.se>=W) return false;
	}
	return true;
}
#ifdef DEBUG
void show_poly(vector<pl> p){ // real positions
	vector<string> s(H,string(W,'.'));
	for(auto e:p)s.at(e.fi).at(e.se) = '#';
	for(auto e:s) cerr<<e<<endl;
}
#endif
/**
int main(){
	cin>>H>>W;
	S.resize(H);rep(i,H)cin>>S.at(i);
	vector<pl> poly = set_poly(S);
	rep(r,4){
		show("rotate",r);
		rep(i,H){
			bool flag = false;
			rep(j,W){
				vector<pl> p = get_poly(pl(i,j),poly);
				if(check_poly(p)){
					show(i,j);
					show_poly(p); flag = true; break;
				}
			}
			if(flag)break;
		}
		rotate_poly(poly);
	}
	return 1;
}
**/
// poliomino
