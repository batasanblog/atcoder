// compare struct for map , sort ,etc... default: greater
struct scomp{
	bool operator()(const pl &a, const pl &b) const noexcept{
		if(a.fi == b.fi) return a.se > b.se; // ko-jun
		else return a.fi > b.fi; // ko-jun
	}
};
/**
sort(be(e.se),[&](ll a,ll b){return X.at(a)<X.at(b);});
map<pl,ll,scomp> mp;
map<pl,ll,greater<pl>> mp_gr;
priority_queue<pl,vector<pl>,scomp> pq;
int main(){
	sort(be(v),scomp{});
}
**/
// End of compare.hpp
