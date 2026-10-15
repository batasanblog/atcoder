// Start matrix double Gauss Jordan
const double EPS = DBL_EPSILON;
template<class T> struct Matrix {
	vector<vector<T> > val;
	Matrix(int n, int m, T x = 0) : val(n, vector<T>(m, x)) {}
	void init(int n, int m, T x = 0) {val.assign(n, vector<T>(m, x));}
	size_t size() const {return val.size();}
	inline vector<T>& operator [] (int i) {return val[i];}
};

template<class T> int GaussJordan(Matrix<T> &A, bool is_extended = false) {
	int m = A.size(), n = A[0].size();
	int rank = 0;
	for (int col = 0; col < n; ++col) {
		if (is_extended && col == n-1) break;
		int pivot = -1;
		T ma = EPS;
		for (int row = rank; row < m; ++row) {
			if (abs(A[row][col]) > ma) {
				ma = abs(A[row][col]);
				pivot = row;
			}
		}
		if (pivot == -1) continue;
		swap(A[pivot], A[rank]);
		{
			auto fac = A[rank][col];
			for (int col2 = 0; col2 < n; ++col2) A[rank][col2] /= fac;
		}
		for (int row = 0; row < m; ++row) {
			if (row != rank && abs(A[row][col]) > EPS) {
				auto fac = A[row][col];
				for (int col2 = 0; col2 < n; ++col2) {
					A[row][col2] -= A[rank][col2] * fac;
				}
			}
		}
		++rank;
	}
	return rank;
}

template<class T> vector<T> linear_equation(Matrix<T> A, vector<T> b) {
	int m = A.size(), n = A[0].size();
	Matrix<T> M(m, n + 1);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
		M[i][n] = b[i];
	}
	int rank = GaussJordan(M, true);
	vector<T> res;
	for (int row = rank; row < m; ++row) if (abs(M[row][n]) > EPS) return res;
	res.assign(n, 0);
	for (int i = 0; i < rank; ++i) res[i] = M[i][n];
	return res;
}
/**
int main(){
	Matrix<ll> Z(N,N);
	rep(n,N){
		Z[n][n] = 1;
		Z[n][(n+1)%N] = 1;
	}
	vl ans = linear_equation(Z,A);
	show(Z.val);
	show(ans.size(),ans);
}	
**/
// End matrix double
