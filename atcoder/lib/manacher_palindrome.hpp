// Manacher Palindrome
// only odd lenghth
vl manacher_core(const string&s){
	vector<ll>radius(s.size());
	ll i=0,j=0;
	while(i<at(s)){
		while(i-j>=0&&i+j<at(s)&&s[i-j]==s[i+j]){
			++j;
		}
		radius[i]=j;
		ll k=1;
		while(i-k>=0&&i+k<at(s)&&k+radius[i-k]<j){
			radius[i+k]=radius[i-k];
			++k;
		}
		i+=k;
		j-=k;
	}
	return radius;
}
// return max palindrome
string manacher(const string&s){
	ll n=s.size();
	string t(n+n-1,'#');
	rep(i,n)t.at(i*2)=s.at(i);
	vl v=manacher_core(t);
	auto it=max_element(be(v));
	ll mx=*it;
	string ans;
	for(auto i=it-mx+1;i<it+mx;++i){
		ll j=i-v.begin();
		if(t.at(j)!='#')ans.pb(t.at(j));	
	}
	return ans;
}
/**
int main(){
	string S; cin>>S;
	show(manacher(S));
	return 0;
}
**/
// Manacher Palindrome
