// Mo
struct Mo {
	ll n;
	vector<pl>lr;
	explicit Mo(ll _n):n(_n){}

	void add(ll l,ll r) { /* [l, r) */
		lr.eb(l,r);
	}

	template<typename AL,typename AR,typename EL,typename ER,typename O>
		void build(const AL&add_left,const AR&add_right,const EL&erase_left,const ER&erase_right, const O&out){
			ll q=(ll)lr.size();
			ll bs=n/min<ll>(n,sqrt(q));
			vector<ll>ord(q);
			iota(begin(ord),end(ord),0);
			sort(begin(ord),end(ord),[&](ll a,ll b){
					auto[La,Ra]=lr[a];
					auto[Lb,Rb]=lr[b];
					ll ablock=La/bs,bblock=Lb/bs;
					if(ablock!=bblock)return ablock<bblock;
					return (ablock&1)?Ra>Rb:Ra<Rb;
					});
			ll l=0,r=0;
			for(auto idx:ord){
				auto[L,R]=lr[idx];
				while(l>L)add_left(--l);
				while(r<R)add_right(r++);
				while(l<L)erase_left(l++);
				while(r>R)erase_right(--r);
				out(idx);
			}
		}

	template<typename A,typename E,typename O>
		void build(const A&add,const E&erase,const O&out){
			build(add,add,erase,erase,out);
		}
};
/** 
const ll MX=500001
ll logic(){
	Mo mo(N);
	rep(qi,Q){
		ll l,r;cin>>l>>r;--l;
		mo.add(l,r);
	}
	vl ct(MX), ans(Q);
	ll sm=0;
	auto add=[&](ll i){
		if(ct.at(A.at(i))++ == 0) ++sm;
	};
	auto erase=[&](ll i){
		if(--ct.at(A.at(i)) == 0) --sm;
	};
	auto out=[&](ll q){
		ans.at(q) = sm;
	};
	mo.build(add,erase,out);
	for(auto e:ans)cout<<e<<endl;
	return 1;
}
*/
/*
	ABC405G

const ll B=512;
ll logic(){
	Mo mo(N);
	vector<mint>ans(Q);
	vl xs(Q);
	rep(qi,Q){
		ll l,r,x;cin>>l>>r>>x;--l;--x;
		mo.add(l,r);
		at(xs,qi)=x;
	}
	vl ca(N);
	vl cb(B);
	vector<mint>ia(N,1);
	vector<mint>ib(B,1);
	auto add=[&](ll i){
		auto a=at(A,i);
		at(ca,a)++;
		at(cb,a/B)++;
		at(ia,a)*=invs(at(ca,a));
		at(ib,a/B)*=invs(at(ca,a));
	};
	auto erase=[&](ll i){
		auto a=at(A,i);
		at(ia,a)*=at(ca,a);
		at(ib,a/B)*=at(ca,a);
		at(ca,a)--;
		at(cb,a/B)--;
	};
	auto out=[&](ll q){
		ll x=at(xs,q);
		ll c=0;
		mint i=1;
		while(x%B){
			x--;
			c+=at(ca,x);
			i*=at(ia,x);
		}
		x/=B;
		while(x){
			x--;
			c+=at(cb,x);
			i*=at(ib,x);
		}
		at(ans,q)=facts(c);
		at(ans,q)*=i;
	};
	mo.build(add,erase,out);
	for(auto a:ans)cout<<a.val()<<'\n';
	#ifdef DEBUG
	cerr << "--- Answer ---" << endl;
	#endif
	return 1;
}

**/
