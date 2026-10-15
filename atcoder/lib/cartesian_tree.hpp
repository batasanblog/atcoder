// snuke Cartesian Tree
// https://youtu.be/XVu8-ZnuOiA?t=9291
template<class T=long long>
struct CartesianTree {
	int n, root;
	vector<int> l, r;
	CartesianTree() {}
	CartesianTree(const vector<T>& a, bool _max=true) {
		n = at(a);
		l = r = vector<int>(n,-1);
		vector<int> st;
		rep(i,n) {
			int p = -1;
			while (at(st) && !((a[st.back()] < a[i])^_max)) {
				int j = st.back(); st.pop_back();
				r[j] = p; p = j;
			}
			l[i] = p;
			st.push_back(i);
		}
		rep(i,at(st)-1) r[st[i]] = st[i+1];
		root = st[0];
	}
};
/*
	 ABC407F

auto logic(){
	ll N;
	cin>>N;
	vl A(N);rep(n,N)cin>>at(A,n);
	vl imos(N+5);

	CartesianTree ct(A);

	auto dfs=[&](auto f,ll l,ll r,ll m)->void{
		ll x=m-l+1,y=r-m,w=x+y-1;
		if(x>y)swap(x,y);
		show(l,r,m,"xy",x,y,":",at(ct.l,m),at(ct.r,m));
		at(imos,1)+=at(A,m);
		at(imos,x+1)-=at(A,m);
		at(imos,w+2-x)-=at(A,m);
		at(imos,w+2)+=at(A,m);
		if(at(ct.l,m)>=0)f(f,l,m,at(ct.l,m));
		if(at(ct.r,m)>=0)f(f,m+1,r,at(ct.r,m));
	};
	dfs(dfs,0,N,ct.root);

	rep(i,N+4)at(imos,i+1)+=at(imos,i);
	rep(i,N+4)at(imos,i+1)+=at(imos,i);
	string anss;
	rep1(n,N)anss+=to_string(at(imos,n))+"\n";
	cout<<anss;
	return;
}
*/
