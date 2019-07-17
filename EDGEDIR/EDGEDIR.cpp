#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int n, m; cin >> n >> m; cout << '\n') {
        vector<int> graph[n];
        set<int> result[n];
        pair<int, int> edges[m];
        for (int i = 0; i < m; i++) {
            cin >> edges[i].first >> edges[i].second;
            --edges[i].first, --edges[i].second;
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        if (m % 2 == 1) {
            cout << "-1\n";
            continue;
        }
        vector<int> indeg(n, 0), depth(n, -1);
        function<void(int, int)> dfs = [&](int v, int parent) {
            for (int u : graph[v]) {
                if (depth[u] == -1) {
                    depth[u] = depth[v] + 1;
                    dfs(u, v);
                } else if (depth[u] > depth[v]) {
                    result[u].emplace(v);
                    indeg[v]++;
                }
            }
            if (parent != -1) {
                if (indeg[v] % 2 == 1) {
                    result[parent].emplace(v);
                    indeg[v]++;
                } else {
                    result[v].emplace(parent);
                    indeg[parent]++;
                }
            }
        };
        depth[0] = 0;
        dfs(0, -1);
        for (auto& p : edges) {
            if (result[p.first].count(p.second) != 0) {
                cout << "0 ";
            } else {
                cout << "1 ";
            }
        }
    }
    return 0;
}
