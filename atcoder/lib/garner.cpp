
// a[k]=m[0]m[1]m[2]...m[k-1]
// b[k]=t[0]+t[1]*m[0]+...+t[k-1]m[0]m[1]...m[k-2]
ll garner(vl&rs,vl ms,ll mod){
	ms.pb(mod);
	vl a(ms.size(),1),b(ms.size(),0);
	rep(k,rs.size()){
		ll mk=at(ms,k);
		ll t=at(rs,k)-at(b,k);
		t*=inv_mod(at(a,k),mk);
		t=(t%mk+mk)%mk;
		reps(i,k+1,ms.size()){
			ll mi=at(ms,i);
			at(b,i)=(at(b,i)+t*at(a,i))%mi;
			at(a,i)=(at(a,i)*mk)%mi;
		}
	}
	return b.back();
}
// yukicoder 184 chukafu
/*
ll logic(){
	mint lcm=1;
	rep(i,N)rep(j,i){
		auto g=gcd(at(Y,i),at(Y,j));
		if((at(X,i)-at(X,j))%g!=0){
			cout<<-1<<endl;
			return 0;
		}
	}
	map<ll,pl>mp;
	rep(n,N){
		auto y=at(Y,n);
		auto pf=prime_factor_pair(y);
		for(auto[a,b]:pf){
			if(mp[a].fi<b)mp[a]=pl(b,n);
		}
	}
	for(auto[k,v]:mp){
		rep(i,v.fi)lcm*=k;
	}
	rep(n,N){
		auto&y=at(Y,n);
		auto pf=prime_factor_pair(y);
		for(auto[a,b]:pf){
			if(mp[a]==pl(b,n))continue;
			rep(i,b)y/=a;
			at(X,n)%=y;
		}
	}
	bool all_zero=true;
	rep(n,N)if(at(X,n)!=0)all_zero=false;
	if(all_zero){
		cout<<lcm.val()<<endl;
		return 0;
	}
	#ifdef DEBUG
	show("X",X);
	show("Y",Y);
	show("mp",mp);
	cerr << "--- Answer ---" << endl;
	#endif
	mint ans=garner(X,Y,mint::mod());
	cout<<ans.val()<<endl;
	//ll ans=Garner(X,Y,mint::mod());
	//cout<<ans<<endl;
	return 1;
}
int main(){
	input();
	#ifdef DEBUG
	showall();
	cerr << "--- Logic ---" << endl;
	#endif
	logic();
	//cout<<logic()<<endl;
	//if(logic())cout<<"Yes"<<endl;
	//else cout<<"No"<<endl;
	//while(input())logic();
	return 0;
}
//cout << fixed << setprecision(16);
*/
