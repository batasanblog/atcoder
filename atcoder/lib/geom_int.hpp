// Geometry Integer based on snuke-san's geom
// Vector
struct V {
  ll x,y;
  V(ll _x=0, double _y=0):x(_x),y(_y){}
	bool operator==(const V&d)const{return x==d.x&&y==d.y;}
  V&operator+=(const V&v){x+=v.x;y+=v.y;return *this;}
  V operator+(const V&v)const{return V(*this)+=v;}
  V&operator-=(const V&v){x-=v.x;y-=v.y;return *this;}
  V operator-(const V&v)const{return V(*this)-=v;}
  V&operator*=(ll s){x*=s;y*=s;return *this;}
  V operator*(ll s)const{return V(*this)*=s;}
  V& operator/=(ll s){x/=s;y/=s; return *this;}
  V operator/(ll s)const{return V(*this)/=s;}
  ll dot(const V&v)const{return x*v.x+y*v.y;}
  ll cross(const V&v)const{return x*v.y-v.x*y;}
  ll norm2()const{return x*x+y*y;}
  double norm()const{return sqrt(norm2());}
	V normalize()const{
		ll g=gcd(x,y);
		return V(x/g,y/g);
	}
  V rotate90()const{return V(y,-x);}
  ll ort()const{ // orthant
    if(x==0&&y==0)return 0;
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
  ll norm2()const{return dir().norm2();}
	double norm()const{return dir().norm();}
  /* +1: s-t,s-p : ccw
   * -1: s-t,s-p : cw
   * +2: t-s-p online but not touch
   * -2: s-t-p online but not touch and reverse
   *  0: s-p-t */
  int ccw(const V& p)const{
    if(dir().cross(p-s)>0)return +1;
    if(dir().cross(p-s)<0)return -1;
    if(dir().dot(p-s)<0)return +2; // out of line  
    if(dir().dot(t-p)<0)return -2; // out of line
    return 0; // on the line
  }
  bool touch(const Line& l)const{
    int a=ccw(l.s)*ccw(l.t),b=l.ccw(s)*l.ccw(t);
    return !a||!b||(a==-1&&b==-1);
  }
};
ostream& operator<<(ostream& os,const Line&l){
	os<<l.s<<"->"<<l.t;return os;
}
/* ABC442E
auto logic(){
	ll N,Q;
	cin>>N>>Q;
	vector<V>A(N);
	map<V,ll>mp;
	rep(n,N){
		ll x,y;cin>>x>>y;
		at(A,n)=V(x,y);
		ll g=gcd(x,y);
		x/=g;y/=g;
		mp[V(x,y)]++;
	}
	map<V,ll>key;
	vl v;
	for(auto[k,c]:mp){
		key[k]=at(key);
		v.pb(c);
	}
	v.insert(v.end(),be(v));
	vl sm(at(v)+1);
	rep(i,at(v))at(sm,i+1)=at(sm,i)+at(v,i);
	string anss;
	rep(qi,Q){
		ll a,b;cin>>a>>b;--a;--b;
		ll l=key[at(A,a)],r=key[at(A,b)];
		if(l>r)r+=at(mp);
		ll ans=at(sm,r+1)-at(sm,l);
		anss+=to_string(ans)+="\n";
	}
	cout<<anss;
	return;
}
*/
