// KMP
struct KMP {
	vl a;
	KMP(){}
	KMP(const string& s):a(s.size()+1,-1) {
		int i = 0, j = -1;
		while (i < s.size()) {
			while (~j && s[i] != s[j]) j = a[j]; //
			a[++i] = ++j;
			// if (i < sz(s) && s[i] == s[j]) a[i] = a[j]; // Knuth
		}
	}
	inline int operator[](int i) { return a[i];}
};
//
string con(const string& s) {
	KMP kmp(s);
	int c = s.size()-kmp[s.size()];
	if (s.size()%c == 0) return s.substr(0,c);
	return s;
}
/**
ll logic(){
	KMP km(S);
	show("kmp",km.a);
	return 1;
}
**/
