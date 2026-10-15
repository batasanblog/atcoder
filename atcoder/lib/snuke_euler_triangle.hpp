// nCr Combination
vector<vl> comb(ll n){
	vector<vl> c(n+1,vl(n+1));
	c.at(0).at(0) = 1;
	rep(i,n)rep(j,i+1){
		c.at(i+1).at(j) += c.at(i).at(j);
		c.at(i+1).at(j+1) += c.at(i).at(j);
	}
	return c;
}
/**
int main(){
	ll N; show("N>>"); cin>>N;
	show(comb(N));
	return 0;
}
**/
// nCr Combination
