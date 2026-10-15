// v: fi min(hight), se sum(wide)
ll hisogram_largest_rectangle(vector<pl>&v){
	ll ret=0;
	v.eb(0,0);
	vector<pl> q;
	for(auto&[mn,s]:v){
		ll w=0;
		while(!q.empty()&&q.back().fi>=mn){
			w+=q.back().se;
			ret=max(ret,w*q.back().fi);
			q.pop_back();
		}
		q.eb(mn,w+s);
	}
	return ret;
}

