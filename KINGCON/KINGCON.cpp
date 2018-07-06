#include <iostream>
#include <vector>
using namespace std;

int result;

int dfs(vector<int>* graph, vector<bool>& visited, int parent, int current, int* depth) {
    visited[current] = true;
    int low = depth[current], child = 0;
    bool isArticulation = false;
    for(auto i : graph[current]) {
        if(!visited[i]) {
            depth[i] = depth[current] + 1;
            int lowi = dfs(graph, visited, current, i, depth);
            child++;
            if(lowi >= depth[current]) {
                isArticulation = true;
            }
            low = min(low, lowi);
        } else if(i != parent) {
            low = min(low, depth[i]);
        }
    }
    if(parent == -1 && child > 1 || parent != -1 && isArticulation) {
        result++;
    }
    return low;
}

int main() {
    int T;
    cin >> T;
    for(int n, m, k; cin >> n >> m >> k; ) {
        vector<int> graph[n];
        vector<bool> visited(n);
        int depth[n];
        for(int a, b; m > 0; m--) {
            cin >> a >> b;
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        result = 0;
        depth[0] = 0;
        dfs(graph, visited, -1, 0, depth);
        cout << result * k << endl;
    }
    return 0;
}
