using td = tuple<double,double,double>; //center, r
using pd = pair<double,double>;
template<typename T> 
T distance(pair<T,T> x,pair<T,T> y){
	auto [x1,y1] = x;
	auto [x2,y2] = y;
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
td circle(vector<pl> &a){
	auto [x1,y1] = a.at(0);
	auto [x2,y2] = a.at(1);
	auto [x3,y3] = a.at(2);
	double d = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
	double x = ((x1*x1 + y1*y1) * (y2 - y3) + (x2*x2 + y2*y2) * (y3 - y1) + (x3*x3 + y3*y3) * (y1 - y2)) / d;
	double y = ((x1*x1 + y1*y1) * (x3 - x2) + (x2*x2 + y2*y2) * (x1 - x3) + (x3*x3 + y3*y3) * (x2 - x1)) / d;
	double r = (x1-x)*(x1-x) + (y1-y)*(y1-y);
	return td(x,y,r);
}
bool isline(vector<pl> &a){
	auto [x1,y1] = a.at(0);
	auto [x2,y2] = a.at(1);
	auto [x3,y3] = a.at(2);
	ll dx1 = x2-x1, dy1 = y2-y1;
	ll dx2 = x3-x2, dy2 = y3-y2;
	if(dx1 == 0 && dx2 == 0) return true;
	if(dy1 == 0 && dy2 == 0) return true;
	if(dx1 == 0 && dy1 == 0) return true;
	if(dx2 == 0 && dy2 == 0) return true;
	if(dx1*dy2 == dx2*dy1) return true;
	return false;
}
vl psort(vector<pl> &a){ //return sorted distance 
	auto [x1,y1] = a.at(0);
	auto [x2,y2] = a.at(1);
	auto [x3,y3] = a.at(2);
	vl ret(3);
	ret.at(0) = distance(a.at(0),a.at(1));
	ret.at(1) = distance(a.at(1),a.at(2));
	ret.at(2) = distance(a.at(2),a.at(0));
	sort(be(ret));
	return ret;
}
