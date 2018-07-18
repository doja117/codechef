#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; ) {
        vector<int> graph[n];
        vector<bool> visited(n);
        pair<int, long long> result {0, 1};
        for(int a, b; m > 0; m--) {
            cin >> a >> b;
            graph[a - 1].emplace_back(b - 1);
            graph[b - 1].emplace_back(a - 1);
        }
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                result.first++;
                long long size = 0;
                visited[i] = true;
                stack<int> stack;
                stack.emplace(i);
                do {
                    auto top = stack.top();
                    stack.pop();
                    size++;
                    for(auto j : graph[top]) {
                        if(!visited[j]) {
                            visited[j] = true;
                            stack.emplace(j);
                        }
                    }
                } while(!stack.empty());
                result.second = (result.second * size) % MOD;
            }
        }
        cout << result.first << ' ' << result.second << endl;
    }
    return 0;
}
