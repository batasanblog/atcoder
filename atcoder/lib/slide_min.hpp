vl slide_min(vl &a,ll w){
	vl id; deque<ll> qu;
	rep(n,a.size()){
		while(!qu.empty()){
			auto p = qu.back();
			if(a.at(p) >= a.at(n)) qu.pop_back();
			else break;
		}
		qu.pb(n);
		ll f = qu.front();
		if(n >= w - 1) id.pb(f);
		if(f <= n - w + 1) qu.pop_front();
	}
	vl ret(id.size());
	rep(i,id.size()) ret.at(i)=a.at(id.at(i));
	return ret;
}
vl slide_max(vl &a,ll w){
	vl id; deque<ll> qu;
	rep(n,a.size()){
		while(!qu.empty()){
			auto p = qu.back();
			if(a.at(p) <= a.at(n)) qu.pop_back();
			else break;
		}
		qu.pb(n);
		ll f = qu.front();
		if(n >= w - 1) id.pb(f);
		if(f <= n - w + 1) qu.pop_front();
	}
	vl ret(id.size());
	rep(i,id.size()) ret.at(i)=a.at(id.at(i));
	return ret;
}
vl slide_min_subset(vl a,ll w){
	ll n=a.size(); w--;
	while(w>0){
		ll d=(w+1)>>1;
		for(ll i=0;i+d<n;i++)a.at(i)=min(a.at(i),a.at(i+d));
		w-=d;
	}
	return a;
}
vl slide_max_subset(vl a,ll w){
	ll n=a.size(); w--;
	while(w>0){
		ll d=(w+1)>>1;
		for(ll i=0;i+d<n;i++)a.at(i)=max(a.at(i),a.at(i+d));
		w-=d;
	}
	return a;
}
