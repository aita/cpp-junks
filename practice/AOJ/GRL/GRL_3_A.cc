#include <vector>
#include <set>
#include <iostream>
#include <functional>

using namespace std;

using Graph = vector<vector<int>>;

set<int> articulation_point(const Graph& G) {
    const auto N = G.size();
    vector<bool> seen(G.size(), false);
    vector<int> prenum(N);
    vector<int> parent(N);
    vector<int> lowest(N);

    int timer = 1;
    function<void(int, int)> visit;
    visit = [&](int cur, int prev) {
        prenum[cur] = lowest[cur] = timer++;
        if (seen[cur])
            return;

        seen[cur] = true;
        for (auto next : G[cur]) {
            if (!seen[next]) {
                parent[next] = cur;
                visit(next, cur);
                lowest[cur] = min(lowest[cur], lowest[next]);
            } else if (next != prev) {
                lowest[cur] = min(lowest[cur], prenum[next]);
            }
        }
    };
    visit(0, -1);

    set<int> ap;
    int np = 0;
    for (int i = 1; i < N; ++i) {
        auto p = parent[i];
        if (p == 0) {
            ++np;
        } else if (prenum[p] <= lowest[i]) {
            ap.insert(p);
        }
    }
    if (np > 1) {
        ap.insert(0);
    }
    return std::move(ap);
}

int main() {
    int V, E;
    cin >> V >> E;
    Graph G(V);
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    for (auto x : articulation_point(G)) {
        cout << x << endl;
    }

    return 0;
}