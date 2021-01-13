#include <vector>
#include <iostream>
#include <functional>

using namespace std;

void topological_sort(vector<vector<int>> G, vector<int>& ans) {
    vector<bool> seen(G.size());

    function<void(int)> visit;
    visit = [&](auto key) {
        if (seen[key])
            return;
        seen[key] = true;
        for (auto x : G[key]) {
            if (seen[x]) {
                continue;
            }
            visit(x);
        }
        ans.push_back(key);
    };

    for (int i = 0; i < G.size(); ++i) {
        visit(i);
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }

    vector<int> ans;
    topological_sort(G, ans);
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
        cout << *it << endl;
    }

    return 0;
}