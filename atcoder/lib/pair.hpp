pl operator-(const pl&x,const pl&y){
	return pl(x.fi-y.fi,x.se-y.se);
}
pl operator-=(pl&x,const pl&y){
	return pl(x.fi-=y.fi,x.se-=y.se);
}
pl operator+(const pl&x,const pl&y){
	return pl(x.fi+y.fi,x.se+y.se);
}
pl operator+=(pl&x,const pl&y){
	return pl(x.fi+=y.fi,x.se+=y.se);
}
