// Combination: (a+b)Ca
vector<vl> nCr(ll a, ll b){
	vector<vl> dp(a+1,vl(b+1)); dp.at(0).at(0) = 1;
	rep(i,a+1)rep(j,b+1){
		if(j)dp.at(i).at(j) += dp.at(i).at(j-1);
		if(i)dp.at(i).at(j) += dp.at(i-1).at(j);
	}
	return dp;
}
// Combination
