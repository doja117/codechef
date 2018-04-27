#include <iostream>
#include <stack>
using namespace std;

int dfs(int start, string* graph) {
    stack<pair<int, int>> stack;
    int result = 0;
    if(graph[start][0] == '.') {
        stack.emplace(start, 0);
        do {
            auto top = stack.top();
            if(top.second == graph[0].size() - 1) {
                return result;
            }
            stack.pop();
            if(graph[top.first][top.second + 1] == '.') {
                stack.emplace(top.first, top.second + 1);
            } else if(graph[1 - top.first][top.second + 1] == '.') {
                stack.emplace(1 - top.first, top.second + 1);
                result++;
            }
        } while(!stack.empty());
    }
    return graph[0].size();
}

int main() {
    int t;
    cin >> t;
    for(string graph[2]; cin >> graph[0] >> graph[1]; ) {
        int result = min(dfs(0, graph), dfs(1, graph));
        if(result < graph[0].size()) {
            cout << "Yes\n" << result << endl;
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
