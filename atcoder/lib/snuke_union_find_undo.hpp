#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;
using P = pair<int,int>;

// UnionFind
// coding: https://youtu.be/TdR816rqc3s?t=726
// comment: https://youtu.be/TdR816rqc3s?t=6822
struct UnionFind {
  vector<int> d;
  vector<pair<int,int>> hist;
  vector<int> snap;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    hist.emplace_back(x,d[x]); d[x] += d[y];
    hist.emplace_back(y,d[y]); d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
  void snapshot() {
    snap.push_back(hist.size());
  }
  void rollback() {
    while (hist.size() > snap.back()) {
      auto [i,x] = hist.back(); hist.pop_back();
      d[i] = x;
    }
    snap.pop_back();
  }
};

const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  vector id(h, vector<int>(w, -1));
  int n = 0;
  vector<P> ps;
  rep(i,h)rep(j,w) if (s[i][j] == '#') {
    id[i][j] = n++;
    ps.emplace_back(i,j);
  }

  int now = 0;
  UnionFind uf(n);
  vector<bool> added(n);
  auto add = [&](int v) {
    now++;
    auto [i,j] = ps[v];
    rep(dir,4) {
      int ni = i+di[dir], nj = j+dj[dir];
      if (ni<0 || nj<0 || ni>=h || nj>=w) continue;
      if (s[ni][nj] != '#') continue;
      int u = id[ni][nj];
      if (added[u] && !uf.same(u,v)) {
        uf.unite(v,u);
        now--;
      }
    }
    added[v] = true;
  };

  mint ans = 0;
  auto f = [&](auto f, int l, int r) -> void {
    if (r-l == 1) {
      ans += now;
      return;
    }
    int c = (l+r)/2;

    int old = now;
    uf.snapshot();
    for (int i = c; i < r; i++) add(i);
    f(f,l,c);
    uf.rollback();
    for (int i = c; i < r; i++) added[i] = false;
    now = old;

    uf.snapshot();
    for (int i = l; i < c; i++) add(i);
    f(f,c,r);
    uf.rollback();
    for (int i = l; i < c; i++) added[i] = false;
    now = old;
  };
  f(f,0,n);

  ans /= n;
  cout << ans.val() << endl;
  return 0;
}
