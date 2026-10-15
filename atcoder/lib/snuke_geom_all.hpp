// Geometry
const double eps = 1e-9;
bool equal(double a, double b) { return abs(a-b) < eps;}

// Vector
// https://youtu.be/UWbGRhF3Ozw?t=9564
struct V {
  double x,y;
  V(double _x=0, double _y=0): x(_x), y(_y){}
	bool operator==(const V&d)const{return abs(x-d.x)<eps&&abs(y-d.y)<eps;}
  V&operator+=(const V&v){x+=v.x;y+=v.y;return *this;}
  V operator+(const V&v)const{return V(*this)+=v;}
  V&operator-=(const V&v){x-=v.x;y-=v.y;return *this;}
  V operator-(const V&v)const{return V(*this)-=v;}
  V&operator*=(double s){x*=s;y*=s;return *this;}
  V operator*(double s)const{return V(*this)*=s;}
  V& operator/=(double s){x/=s;y/=s; return *this;}
  V operator/(double s)const{return V(*this)/=s;}
  double dot(const V&v)const{return x*v.x+y*v.y;}
  double cross(const V&v)const{return x*v.y-v.x*y;}
  double norm2()const{return x*x+y*y;}
  double norm()const{return sqrt(norm2());}
  V normalize()const{return *this/norm();}
  V rotate90()const{return V(y,-x);}
  int ort()const{ // orthant
    if(abs(x)<eps&&abs(y)<eps)return 0;
    if(y>=0&&x>0)return 1;
		if(y>0&&x<=0)return 2;
		if(y<=0&&x<0)return 3;
		if(y<0&&x>=0)return 4;
		assert(false);
  }
  bool operator<(const V&v)const{
    int o=ort(),vo=v.ort();
    if(o!=vo)return o<vo;
    return cross(v)>0;
  }
};
istream& operator>>(istream& is,V&v){
  is>>v.x>>v.y;return is;
}
ostream& operator<<(ostream& os,const V&v){
  os<<"("<<v.x<<","<<v.y<<")"; return os;
}

struct Line{
  V s,t;
  Line(V _s=V(0,0),V _t=V(0,0)):s(_s),t(_t){}
  V dir()const{return t-s;}
  V normalize()const{return dir().normalize();}
  double norm()const{return dir().norm();}
  /* +1: s-t,s-p : ccw
   * -1: s-t,s-p : cw
   * +2: t-s-p online but not touch
   * -2: s-t-p online but not touch and reverse
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


// return line : point to line as vertical
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

// Circle
// coding: https://youtu.be/TdR816rqc3s?t=1750
// comment: https://youtu.be/TdR816rqc3s?t=11609
struct Circle {
  V o; double r;
  //Circle(V o=V(),double r=0) : o(o), r(r) {}
	Circle(V _o=V(),double _r=0):o(_o), r(_r) {}
  vector<V> crossPoint(const Circle& c) {
    V v = c.o-o;
    double l = v.norm();
    if (equal(l, 0)) return {};
    if (equal(l+r+c.r, max({l,r,c.r})*2)) {
      if (equal(l+r,c.r)) return {o - v*(r/l)};
      return {o + v*(r/l)};
    }
    if (l+r+c.r < max({l,r,c.r})*2) return {};
    double x = (l*l + r*r - c.r*c.r) / (2*l);
    double y = sqrt(r*r - x*x);
    V mid = o + v*(x/l);
    v = v.rotate90();
    return {mid + v*(y/l), mid - v*(y/l)};
  }
  bool isInside(const V& p) const {
    return (p-o).norm() < r+eps;
  }
};
/*
auto logic(){
	ll x,y;cin>>x>>y;
	V v(x,y);
	show(x,y,"ort",v.ort());
	return;
}
*/

