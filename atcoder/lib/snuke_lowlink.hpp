#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;
using P = pair<int,int>;

struct Lowlink {
  struct Edge {
    int to, id;
    Edge() {}
    Edge(int to, int id=-1): to(to), id(id) {}
  };
  int n, m;
  vector<vector<Edge>> g;
  vector<pair<int,int>> edges;
  Lowlink(int n): n(n), m(0), g(n) {}
  void addEdge(int a, int b) {
    if (a > b) swap(a,b);
    edges.emplace_back(a,b);
    g[a].emplace_back(b,m);
    g[b].emplace_back(a,m++);
  }

  vector<int> ord, low, par;
  void init() {
    ord = low = par = vector<int>(n,-1);
    int k = 0;
    auto dfs = [&](auto dfs, int v, int ei=-1) -> int {
      low[v] = ord[v] = k++;
      for (auto e : g[v]) if (e.id != ei) {
        if (ord[e.to] == -1) {
          par[e.to] = v;
          low[v] = min(low[v], dfs(dfs, e.to, e.id));
        } else if (ord[e.to] < ord[v]) {
          low[v] = min(low[v], ord[e.to]);
        }
      }
      return low[v];
    };
    rep(v,n) if (ord[v] == -1) dfs(dfs,v);
  }

  vector<vector<int>> bc;
  vector<int> bc_id;
  void bcc() { // Bi-Connected-Components
    bc_id = vector<int>(m,-1);
    auto add = [&](int ei, int k) {
      bc[k].push_back(ei);
      bc_id[ei] = k;
    };
    auto dfs = [&](auto dfs, int v, int k=-1) -> void {
      for (auto e : g[v]) if (e.to != par[v]) {
        if (par[e.to] == v) {
          int nk = k;
          if (low[e.to] >= ord[v]) nk = bc.size(), bc.emplace_back();
          add(e.id, nk);
          dfs(dfs, e.to, nk);
        } else if (ord[e.to] < ord[v]) {
          add(e.id, k);
        }
      }
    };
    rep(v,n) if (par[v] == -1) dfs(dfs, v);
    /*
    rep(i,m) {
      auto [a,b] = edges[i];
      printf("%d %d-%d: %d\n", i, a, b, bc_id[i]);
    }
    rep(v,n) {
      printf("%d: %d %d\n", v, ord[v], low[v]);
    }//*/
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

  Lowlink g(n);
  rep(i,h)rep(j,w) if (s[i][j] == '#') {
    rep(v,2) {
      int ni = i+di[v], nj = j+dj[v];
      if (ni<0 || nj<0 || ni>=h || nj>=w) continue;
      if (s[ni][nj] != '#') continue;
      int a = id[i][j], b = id[ni][nj];
      g.addEdge(a,b);
    }
  }
  g.init();
  g.bcc();

  int base = 0;
  rep(v,n) if (g.par[v] == -1) base++;
  mint ans = 0;
  rep(v,n) {
    int now = base-1;
    set<int> st;
    for (auto e : g.g[v]) st.insert(g.bc_id[e.id]);
    now += st.size();
    ans += now;
  }
  ans /= n;
  cout << ans.val() << endl;
  return 0;
}
