struct C {
	int x, y;
	C(int x=0, int y=0) : x(x), y(y) {}
	C operator*(const C& a) const {
		return C(x*a.x-y*a.y, x*a.y+y*a.x);
	}
	C operator-(const C& a) const {
		return C(x-a.x, y-a.y);
	}
	bool operator<(const C& a) const {
		if (x == a.x) return y < a.y;
		return x < a.x;
	};
	bool operator==(const C& a) const {
		return x == a.x && y == a.y;
	};
	int norm() const { return x*x + y*y;}
};
