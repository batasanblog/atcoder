// Matrix mint
struct Matrix{
	ll m,n;
	vector<vector<mint>>v;
	Matrix(ll _m,ll _n,mint x=0):m(_m),n(_n),v(_m,vector<mint>(_n,x)){}
	void push_back(vector<mint>&w){
		assert(at(w)==m);
		rep(i,m)at(v,i).pb(at(w,i));
		n++;
	}
	ll size(){return m;}
	inline vector<mint>&operator[](ll i){return v[i];}
	vector<vector<mint>>&val(){return v;}
};

ll GaussJordan(Matrix&A,bool is_extended=false){
	ll rank=0;
	ll m=A.m,n=A.n;
	for(ll col=0;col<n;++col){
		if(is_extended&&col==n-1)break;
		ll pivot=-1;
		for(ll row=rank;row<m;++row){
			if(A[row][col]!=0){
				pivot=row;
				break;
			}
		}
		if(pivot==-1)continue;
		swap(A[pivot],A[rank]);
		auto inv=1/A[rank][col];
		for(ll col2=0;col2<n;++col2)
			A[rank][col2]=A[rank][col2]*inv;
		for(ll row=0;row<m;++row){
			if(row!=rank&&A[row][col]!=0){
				auto fac=A[row][col];
				for(ll col2=0;col2<n;++col2){
					A[row][col2]-=A[rank][col2]*fac;
				}
			}
		}
		++rank;
	}
	return rank;
}

ll linear_equation(Matrix&A,vector<mint>&b){
	A.pb(b);
	ll m=A.m,n=A.n;
	ll rank=GaussJordan(A,true);

	// check if it has no solution
	for(ll row=rank;row<m;++row){
		if(A[row][n-1]!=0)return -1;
	}

	// answer
	return rank;
}
// End Matrix mint
/*
auto logic(){
	ll N,M;
	cin>>N>>M;
	Matrix A(N,M);
	rep(n,N)rep(m,M){
		ll a;cin>>a;
		at(A,n,m)=a;
	}
	vector<mint>b(N);
	rep(n,N){
		ll a;cin>>a;at(b,n)=a;
	}
	auto r=linear_equation(A,b);
	vector<mint>ans(M);
	if(r<0){
		cout<<-1<<endl;
		return;
	}
	vl num(M,-1);
	ll cnt=0;
	rep(j,M){
		if(at(A,cnt,j)!=0){
			at(num,j)=cnt++;
			if(cnt==r)break;
		}
	}
	cout<<M-r<<'\n';
	rep(i,M){
		mint c=0;
		if(at(num,i)>=0)c=at(A,at(num,i),M);
		cout<<c.val()<<" ";
	}
	cout<<endl;
	rep(j,M)if(at(num,j)<0){
		rep(i,M){
			mint x=1;
			if(i!=j){
				if(at(num,i)<0)x=0;
				else x=-at(A,at(num,i),j);
			}
			cout<<x.val()<<" ";
		}
		cout<<endl;
	}
	return;
}
*/
