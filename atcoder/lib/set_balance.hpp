struct S{
	multiset<ll>s0,s1;
	ll a,b;
	S():a(0),b(0){}
	void add(ll x){
		s0.insert(x);
		a+=x;
		reb();
	}
	void del(ll x){
		auto it=s1.find(x);
		if(it!=s1.end()){
			s1.erase(it);
			b-=x;
		}else{
		 	it=s0.find(x);
			if(it!=s0.end()){
				s0.erase(it);
				a-=x;
			}
		}
		reb();
	}
	void reb(){
		while(at(s0)>at(s1)){
			b+=*--s0.end();
			a-=*--s0.end();
			s1.insert(*--s0.end());
			s0.erase(--s0.end());
		}
		while(at(s0)+1<at(s1)){
			a+=*s1.begin();
			b-=*s1.begin();
			s0.insert(*s1.begin());
			s1.erase(s1.begin());
		}
		while(at(s0)>0&&at(s1)>0&&*--s0.end()>*s1.begin()){
			ll x0=*--s0.end();
			ll x1=*s1.begin();
			s0.erase(--s0.end());
			s1.erase(s1.begin());
			a-=x0;
			b+=x0;
			a+=x1;
			b-=x1;
			s1.insert(x0);
			s0.insert(x1);
		}
	}
};
