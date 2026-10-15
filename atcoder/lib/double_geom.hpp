// Vector
// https://youtu.be/UWbGRhF3Ozw?t=9564
struct V {
	D x, y;
	V(D x=0,D y=0): x(x), y(y) {}
	V& operator+=(const V& v){x+=v.x;y+=v.y;return *this;}
	V operator+(const V& v)const{return V(*this)+=v;}
	V& operator-=(const V& v){x-=v.x;y-=v.y; return *this;}
	V operator-(const V& v)const{return V(*this)-=v;}
	V& operator*=(D s){x*=s;y*=s;return *this;}
	V operator*(D s) const{return V(*this)*=s;}
	V& operator/=(D s){x/=s;y/=s;return *this;}
	V operator/(D s)const{return V(*this)/=s;}
	D dot(const V& v)const{return x*v.x+y*v.y;}
	D cross(const V& v)const{return x*v.y-v.x*y;}
	D norm2() const{return x*x+y*y;}
	D norm() const{return sqrt(norm2().x);}
	V normalize() const{return *this/norm();}
	V rotate90() const{return V(y,-x);}
	int ort() const{ // orthant
		if(x==0&&y==0) return 0;
		if(y>0)return x>0?1:2;
		else return x>0?4:3;
	}
	bool operator<(const V& v) const{
		int o=ort(),vo=v.ort();
		if(o!=vo)return o<vo;
		return cross(v)>0;
	}
};
istream& operator>>(istream& is,V& v){
	is>>v.x.x>>v.y.x; return is;
}
ostream& operator<<(ostream& os,const V& v) {
	os<<"("<<v.x<<","<<v.y<<")"; return os;
}


struct Line{
	V s,t;
	Line(V s=V(0,0),V t=V(0,0)):s(s),t(t){}
	V dir() const{return t-s;}
	V normalize() const{return dir().normalize();}
	D norm() const{return dir().norm();}
	/* +1: s-t,s-p : ccw
	 * -1: s-t,s-p : cw
	 * +2: t-s-p
	 * -2: s-t-p
	 *  0: s-p-t */
	int ccw(const V& p) const{
		if(dir().cross(p-s)>0) return +1;
		if(dir().cross(p-s)<0) return -1;
		if(dir().dot(p-s)<0) return +2;
		if(dir().dot(t-p)<0) return -2;
		return 0;
	}
	bool touch(const Line& l) const{
		int a=ccw(l.s)*ccw(l.t),b=l.ccw(s)*l.ccw(t);
		return !a||!b||(a==-1&&b==-1);
	}
};

// Circle
// coding: https://youtu.be/TdR816rqc3s?t=1750
// comment: https://youtu.be/TdR816rqc3s?t=11609
struct Circle {
	V o; D r;
	Circle(V o=V(), D r=0):o(o),r(r){}
	vector<V> crossPoint(const Circle& c){
		V v=c.o-o;
		D l=v.norm();
		if(l==0)return {};
		if(l+r+c.r==max({l,r,c.r})*2){
			if(l+r==c.r) return {o-v*(r/l)};
			return {o+v*(r/l)};
		}
		if (l+r+c.r < max({l,r,c.r})*2) return {};
		D x=(l*l+r*r-c.r*c.r)/(l*2);
		D y=sqrt(D(r*r-x*x).x);
		V mid=o+v*(x/l);
		v=v.rotate90();
		return {mid+v*(y/l),mid-v*(y/l)};
	}
	bool isInside(const V& p) const {
		return (p-o).norm()<r;
	}
};
