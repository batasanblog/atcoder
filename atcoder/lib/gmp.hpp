// mpq_mint , debug for mint
#ifdef DEBUG
#include <gmpxx.h>
struct mpq_mint{
	mpq_class d;
	mpq_mint(){}
	mpq_mint(long long _d):d(to_string(_d)){}
	mpq_mint(auto _d):d(_d){}
	string val()const{
		mpz_class a=d.get_num();
		mpz_class b=d.get_den();
		modint998244353 c=a.get_si();
		c/=b.get_si();
		return d.get_str()+"="+to_string(c.val());
	}
	mpq_mint operator+(const mpq_mint&a)const{
		return mpq_mint(d+a.d);
	}
	mpq_mint&operator+=(const mpq_mint&a){
		d+=a.d;return *this;
	}
	mpq_mint operator-(const mpq_mint&a)const{
		return mpq_mint(d-a.d);
	}
	mpq_mint&operator-=(const mpq_mint&a){
		d-=a.d;return *this;
	}
	mpq_mint operator/(const mpq_mint&a)const{
		return mpq_mint(d/a.d);
	}
	mpq_mint&operator/=(const mpq_mint&a){
		d/=a.d;return *this;
	}
	mpq_mint operator*(const mpq_mint&a)const{
		return mpq_mint(d*a.d);
	}
	mpq_mint&operator*=(const mpq_mint&a){
		d*=a.d;return *this;
	}
	mpq_mint operator-()const{
		return mpq_mint(-d);
	}
	bool operator==(const mpq_mint&a)const{
		return d==a.d;
	}
};
mpq_mint operator+(const long long &a,const mpq_mint&b){
	return mpq_mint(a)+b;
}
mpq_mint operator-(const long long &a,const mpq_mint&b){
	return mpq_mint(a)-b;
}
mpq_mint operator*(const long long &a,const mpq_mint&b){
	return mpq_mint(a)*b;
}
mpq_mint operator/(const long long &a,const mpq_mint&b){
	return mpq_mint(a)/b;
}
using mint=mpq_mint;
#else
using mint=static_modint<998244353>;
#endif
// end of mpq_mint , debug for mint



struct mpz_ll:mpz_class{
	mpz_ll(){}
	mpz_ll(long long a):mpz_class(to_string(a)){}
	mpz_ll(auto a):mpz_class(a){}
	long long val(){return get_si();}
};

//mpf_set_default_prec(1024);

//ll a=z.get_si();
//mpf_class a((int)xx); // only int, not ll
//mp_exp_t exp;
//mpf_class a(3);
//mpf_class b=sqrt(a)*10000;
//string s=b.get_str(exp); // exp=shisu(exponential)
//mpq_class a(1);  //有理数
/*
mpz_class fib1(int), fib2(int), fib3(int);

mpz_class fib1(int n) {
	if(n <= 1) return n;
	else return fib1(n - 1) + fib1(n - 2);
}

mpz_class fib2(int n) {
	mpz_class a = 1, b = 0;

	for(int i = 0; i < n; ++i) {
		swap(a, b);
		b += a;
	}
	return b;
}

mpz_class fib3(int n) {
	mpz_class a = 1, b = 0, c, d;
	for(int i = 30; i >= 0; --i) {
		c = a * a + b * b;
		d = b * (2 * a + b);
		if((n >> i) & 1) {
			b = c + d;
			swap(a, d);
		} else {
			swap(a, c);
			swap(b, d);
		}
	}
	return b;
}
*/
