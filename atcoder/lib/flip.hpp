void flip(vector<vl> &d){
	rep(i,N)rep(j,i){
		swap(d.at(i).at(j),d.at(j).at(i));
	}
}
