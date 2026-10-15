// 分割数
template<class T> struct Partition {
    vector<vector<T> > P;
    constexpr Partition(int MAX) noexcept : P(MAX, vector<T>(MAX, 0)) {
        for (int k = 0; k < MAX; ++k) P[0][k] = 1;
        for (int n = 1; n < MAX; ++n) {
            for (int k = 1; k < MAX; ++k) {
                P[n][k] = P[n][k-1] + (n-k >= 0 ? P[n-k][k] : 0);
            }
        }
    }
    constexpr T get(int n, int k) {
        if (n < 0 || k < 0) return 0;
        return P[n][k];
    }
};
/**
int main() {
    using mint = Fp<1000000007>;
    Partition<mint> pt(5100);
    int n, k; cin >> n >> k;
    cerr << pt.get(n, k) << endl;
}
**/
