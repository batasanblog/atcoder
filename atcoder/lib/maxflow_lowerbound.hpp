// https://ei1333.github.io/luzhiled/snippets/graph/maxflow-lower-bound.html
template< typename flow_t >
struct Dinic {
	const flow_t INF;

	struct edge {
		int to;
		flow_t cap;
		int rev;
		bool isrev;
		int idx;
	};

	vector< vector< edge > > graph;
	vector< int > min_cost, iter;

	Dinic(int V) : INF(numeric_limits< flow_t >::max()), graph(V) {}

	void add_edge(int from, int to, flow_t cap, int idx = -1) {
		graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
		graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true, idx});
	}

	bool bfs(int s, int t) {
		min_cost.assign(graph.size(), -1);
		queue< int > que;
		min_cost[s] = 0;
		que.push(s);
		while(!que.empty() && min_cost[t] == -1) {
			int p = que.front();
			que.pop();
			for(auto &e : graph[p]) {
				if(e.cap > 0 && min_cost[e.to] == -1) {
					min_cost[e.to] = min_cost[p] + 1;
					que.push(e.to);
				}
			}
		}
		return min_cost[t] != -1;
	}

	flow_t dfs(int idx, const int t, flow_t flow) {
		if(idx == t) return flow;
		for(int &i = iter[idx]; i < graph[idx].size(); i++) {
			edge &e = graph[idx][i];
			if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
				flow_t d = dfs(e.to, t, min(flow, e.cap));
				if(d > 0) {
					e.cap -= d;
					graph[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	flow_t max_flow(int s, int t) {
		flow_t flow = 0;
		while(bfs(s, t)) {
			iter.assign(graph.size(), 0);
			flow_t f = 0;
			while((f = dfs(s, t, INF)) > 0) flow += f;
		}
		return flow;
	}

	void output() {
		for(int i = 0; i < graph.size(); i++) {
			for(auto &e : graph[i]) {
				if(e.isrev) continue;
				auto &rev_e = graph[e.to][e.rev];
				cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
			}
		}
	}
};

// https://ei1333.github.io/luzhiled/snippets/graph/maxflow-lower-bound.html
template< typename flow_t, template< typename > class F >
struct MaxFlowLowerBound {
	F< flow_t > flow;
	vector< flow_t > in, up;
	typename F< flow_t >::edge *latte, *malta;
	int X, Y, V;
	flow_t sum;

	MaxFlowLowerBound(int V) : V(V), flow(V + 2), X(V), Y(V + 1), sum(0), in(V) {}

	void add_edge(int from, int to, flow_t low, flow_t high) {
		assert(from != to);
		flow.add_edge(from, to, high - low, up.size());
		in[from] -= low;
		in[to] += low;
		up.emplace_back(high);
	}

	void build() {
		for(int i = 0; i < V; i++) {
			if(in[i] > 0) {
				flow.add_edge(X, i, in[i]);
				sum += in[i];
			} else if(in[i] < 0) {
				flow.add_edge(i, Y, -in[i]);
			}
		}
	}

	bool can_flow(int s, int t) {
		assert(s != t);
		flow.add_edge(t, s, flow.INF);
		latte = &flow.graph[t].back();
		malta = &flow.graph[s].back();
		return can_flow();
	}

	bool can_flow() {
		build();
		auto ret = flow.max_flow(X, Y);
		return ret >= sum;
	}

	flow_t max_flow(int s, int t) {
		if(can_flow(s, t)) {
			return flow.max_flow(s, t);
		} else {
			return -1;
		}
	}

	flow_t min_flow(int s, int t) {
		if(can_flow(s, t)) {
			auto ret = flow.INF - latte->cap;
			latte->cap = malta->cap = 0;
			return ret - flow.max_flow(t, s);
		} else {
			return -1;
		}
	}

	void output(int M) {
		vector< flow_t > ans(M);
		for(int i = 0; i < flow.graph.size(); i++) {
			for(auto &e : flow.graph[i]) {
				if(!e.isrev && ~e.idx) ans[e.idx] = up[e.idx] - e.cap;
			}
		}
		for(auto &p : ans) cout << p << endl;
	}
};
/*
int main() {
    int oh, ow; cin >> oh >> ow;
    char maze[oh][ow];
    REP(h, oh){
        REP(w, ow) {
            cin >> maze[h][w];
        }
    }
    int n = oh * ow ;
    int nodes = oh * ow; // source
    int nodet = nodes + 1; //
    // create s -> node, node -> t
    MaxFlowLowerBound< int, Dinic > mf(n + 1 + 1);
    REP(h, oh){
        REP(w, ow) {
            if(maze[h][w] == '1') continue; // 1は壁だと思ってよい
            auto node = h * ow + w;
            if(maze[h][w] == '2') {
                // 2の場合は必ず流さないといけない
                if (((h + w) % 2) == 0) mf.add_edge(nodes, node, 1, 1);
                else mf.add_edge(node, nodet, 1, 1);
            }
            else if(maze[h][w] == '?') {
                // ? は流しても流さなくてもいい
                if (((h + w) % 2) == 0) mf.add_edge(nodes, node, 0, 1);
                else mf.add_edge(node, nodet, 0, 1);
            }
            else
                assert(false);
        }
    }
    vector<pair<int, int>> delta = {{-1, 0}, {0, -1}, {0, 1}, { 1, 0}};
    // create node - node
    REP(h, oh){
        REP(w, ow) {
            auto node = h * ow + w;
            if( ((h + w) % 2) != 0) continue; // whiteはいらない
            for(auto &[dh, dw]: delta){
                auto nh = h + dh;
                auto nw = w + dw;
                if(!(0 <= nh && nh < oh)) continue;
                if(!(0 <= nw && nw < ow)) continue;
                if(maze[nh][nw] == '1') continue; // 壁相当には流せない
                auto nxt = nh * ow + nw;
                mf.add_edge(node, nxt, 0, 1);
            }
        }
    }
    // DRAW!
    auto ans = mf.max_flow(nodes, nodet);
    if(ans != -1) cout << "Yes" << "\n";
    else cout << "No" << "\n";

}
*/
