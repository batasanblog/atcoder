// bunkatsu-su rekkyo
bool next_partition(vl& a) {
	if (a.empty())  return false;
	ll sum = a.back(); a.pop_back();
	if (a.empty())  return false;
	while (!a.empty()) {
		ll x = a.back(); a.pop_back();
		sum += x;
		if (a.empty() || a.back() > x) {
			a.push_back(x + 1);
			ll remaining = sum - x - 1;
			a.insert(a.end(), remaining, 1);
			break;
		}
	}
	return true;
}
/**
ll logic(){
	vl v(N,1);
	ll no=1;
	do{
		show(no++,v);
	}while(next_partition(v));
	return 1;
}
**/
