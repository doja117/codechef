#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;

int get_to(pair<int, int> *edge, int from, int index) {
    return edge[index].first + edge[index].second - from;
}

int main() {
    int n, e;
    cin >> n >> e;
    set<int> graph[n];
    pair<int, int> edge[e];
    for(int i = 0, a, b; cin >> a >> b; i++) {
        edge[i] = {a - 1, b - 1};
        graph[a - 1].emplace(i);
        graph[b - 1].emplace(i);
    }
    string result = "YES\n";
    vector<bool> visited(n);
    visited[0] = true;
    stack<int> stack;
    stack.emplace(0);
    do {
        int from = stack.top();
        stack.pop();
        for(auto i : graph[from]) {
            int to = get_to(edge, from, i);
            if(!visited[to]) {
                visited[to] = true;
                stack.emplace(to);
            }
        }
    } while(!stack.empty());
    for(int i = 0; i < n; i++) {
        if(!visited[i] || graph[i].size() % 2 == 1) {
            result = "NO\n";
        }
    }
    cout << result;
    if(result == "YES\n") {
        stack.emplace(0);
        do {
            auto top = stack.top();
            stack.pop();
            while(!graph[top].empty()) {
                auto index = *graph[top].begin(), next = get_to(edge, top, index);
                graph[next].erase(index);
                graph[top].erase(index);
                if(edge[index].first != top) {
                    swap(edge[index].first, edge[index].second);
                }
                stack.emplace(next);
            }
        } while(!stack.empty());
        for(int i = 0; i < e; i++) {
            cout << edge[i].first + 1 << ' ' << edge[i].second + 1 << endl;
        }
    }
    return 0;
}
