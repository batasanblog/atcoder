// rotate string
vector<string> rotate_string_l(vector<string> &s){
	ll h = s.size();
	ll w = s.at(0).size();
	vector<string> t(w,string(h,' '));
	rep(i,h){
		assert(s.at(i).size() == w);
		rep(j,w){
			t.at(w-1-j).at(i) = s.at(i).at(j);
		}
	}
	return t;
}
vector<string> rotate_string_r(vector<string> &s){
	ll h = s.size();
	ll w = s.at(0).size();
	vector<string> t(w,string(h,' '));
	rep(i,h){
		assert(s.at(i).size() == w);
		rep(j,w){
			t.at(j).at(h-1-i) = s.at(i).at(j);
		}
	}
	return t;
}
/**
int main(){
	ll N,M;
	vector<string> S;
	cin>>N>>M;
	S.resize(N);
	rep(n,N)cin>>S.at(n);
	for(auto e:S)cout<<e<<endl;
	show("--- rotate right ---");
	vector<string> t = rotate_string_r(S);
	for(auto e:t)cout<<e<<endl;
	return 1;
}
**/
// rotate string 
