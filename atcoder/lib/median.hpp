struct Median{
	multiset<ll> l,r;
	ll m=INF;
	Median(){}
	void add(ll x){
		if(x<=m) l.insert(x);
		else if(m<x) r.insert(x);
		set();
	}
	void erase(ll x){
		auto i=r.find(x);
		if(i!=r.end()) r.erase(i);
		else{
			i=l.find(x);
			if(i!=l.end()) l.erase(i);
		}
		set();
	}
	void set(){
		if(l.size()==0&&r.size()==0)return;
		while(l.size()<r.size()){
			l.insert(*r.begin());
			r.erase(r.begin());
		}
		while(l.size()>r.size()+1){
			auto it=l.end();
			it--;
			r.insert(*it);
			l.erase(it);
		}
		assert(l.size()==r.size()||l.size()==r.size()+1);
		if(l.size()>r.size()) m=*l.rbegin();
		else m=(*l.rbegin()+*r.begin())/2;
	}
	ll get(){
		return m;
	}
	ll size(){
		return l.size()+r.size();
	}
};

//Median mid;

