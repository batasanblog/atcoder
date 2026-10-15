const double EPS=1e-9;
struct D{
	double x;
	D(double x=0):x(x){}
	double val()const{return x;}
	bool operator==(const D& d) const{
		return abs(x-d.x)<EPS;
	}
	bool operator<(const D& d) const{
		return x+EPS<d.x;
	}
	bool operator<=(const D& d) const{
		return *this==d||*this<d.x;
	}
	bool operator>(const D& d) const{
		return d.x+EPS<x;
	}
	bool operator>=(const D& d) const{
		return *this==d||d<*this;
	}
	D operator+(const D& d) const{
		return D(x+d.x);
	}
	D& operator+=(const D& d) {
		x+=d.x; return *this;
	}
	D operator-(const D& d) const{
		return D(x-d.x);
	}
	D& operator-=(const D& d) {
		x-=d.x; return *this;
	}
	D operator*(const D& d) const{
		return D(x*d.x);
	}
	D& operator*=(const D& d) {
		x*=d.x; return *this;
	}
	D operator/(const D& d) const{
		return D(x/d.x);
	}
	D& operator/=(const D& d) {
		x/=d.x; return *this;
	}
	D operator-() const{
		return D(-x);
	}
};
/*
ostream& operator<<(ostream& o,const D& d){
	o<<d.x;return o;
}
istream& operator>>(istream& is,D& d){
	is>>d.x; return is;
}
*/
