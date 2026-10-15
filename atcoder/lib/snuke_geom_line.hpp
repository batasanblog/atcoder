struct Line{
  V s,t;
  Line(V _s=V(0,0),V _t=V(0,0)):s(_s),t(_t){}
  V dir()const{return t-s;}
  V normalize()const{return dir().normalize();}
  double norm()const{return dir().norm();}
  /* +1: s-t,s-p : ccw
   * -1: s-t,s-p : cw
   * +2: t-s-p
   * -2: s-t-p
   *  0: s-p-t */
  int ccw(const V& p)const{
    if(dir().cross(p-s)>eps)return +1;
    if(dir().cross(p-s)<-eps)return -1;
    if(dir().dot(p-s)<-eps)return +2;
    if(dir().dot(t-p)<-eps)return -2;
    return 0;
  }
  bool touch(const Line& l)const{
    int a=ccw(l.s)*ccw(l.t),b=l.ccw(s)*l.ccw(t);
    return !a||!b||(a==-1&&b==-1);
  }
};
ostream& operator<<(ostream& os,const Line&l){
	os<<l.s<<"->"<<l.t;return os;
}
struct TwoLines{
	Line p,q;
	V a,b,c,d;
	double cross;
	double s,t;
	V koten;
	TwoLines(V _a,V _b,V _c,V _d):a(_a),b(_b),c(_c),d(_d){
		p=Line(a,b);q=Line(c,d);
		set();
	}
	TwoLines(Line _p,Line _q):p(_p),q(_q){
		a=p.s;b=p.t;c=q.s;d=q.t;
		set();
	}
	void set(){
		cross=p.dir().cross(q.dir());
		if(equal(cross,0))return;
		V ac=c-a;
		s=ac.cross(q.dir())/cross;
		t=ac.cross(p.dir())/cross;
		koten=a+p.dir()*s;
		assert(koten==V(c+q.dir()*t));
	}
	bool is_para(){
		return equal(cross,0);
	}
	bool touch(){
		return p.touch(q);
	}
};
Line vertical(Line&l,V&p){
	if(abs(l.ccw(p))!=1)return Line(p,p);
	V vdir=V(l.dir().y,-l.dir().x);
	TwoLines t(l,Line(p,p+vdir));
	return Line(t.koten,p);
}
/*
auto logic(){
	//double a,b,c,d,e,f,g,h;
	V sa,ta,sb,tb;
	cin>>sa>>ta>>sb>>tb;
	show(sa,ta,sb,tb);
	TwoLines t(sa,ta,sb,tb);
	show("sdir",t.p.dir(),"tdir",t.q.dir());
	show("cross",t.cross,"s",t.s,"t",t.t,"koten",t.koten,"touch",t.touch(),"para",t.is_para());
	return;
}
*/
