#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; ) {
        vector<bool> graph[n];
        fill(graph, graph + n, vector<bool>(n));
        for(int a, b; m > 0; m--) {
            cin >> a >> b;
            graph[a - 1][b - 1] = true;
            graph[b - 1][a - 1] = true;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                graph[i][j] = 1 - graph[i][j];
            }
            graph[i][i] = false;
        }
        int color[n];
        fill(color, color + n, -1);
        string result = "YES\n";
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                stack<int> stack;
                stack.emplace(i);
                color[i] = 0;
                do {
                    auto top = stack.top();
                    stack.pop();
                    for(int j = 0; j < n; j++) {
                        if(graph[top][j]) {
                            if(color[j] == -1) {
                                color[j] = 1 - color[top];
                                stack.emplace(j);
                            } else if(color[j] == color[top]) {
                                result = "NO\n";
                            }
                        }
                    }
                } while(!stack.empty());
            }
        }
        cout << result;
    }
    return 0;
}
