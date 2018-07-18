#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const long long MOD = 1000000007;

int index(char c) {
    switch(c) {
        case 'G':
            return 0;
        case 'P':
            return 1;
        case 'B':
            return 2;
        default:
            return 3;
    }
}

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        string graph[n];
        vector<bool> visited[n];
        for(int i = 0; i < n; i++) {
            visited[i] = vector<bool>(n);
            cin >> graph[i];
        }
        long long result = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && graph[i][j] != '.') {
                    visited[i][j] = true;
                    stack<pair<int, int>> stack;
                    stack.emplace(i, j);
                    int count[4] = {};
                    do {
                        auto x = stack.top().first, y = stack.top().second;
                        count[index(graph[x][y])]++;
                        stack.pop();
                        if(x >= 1 && !visited[x - 1][y] && graph[x - 1][y] != '.') {
                            visited[x - 1][y] = true;
                            stack.emplace(x - 1, y);
                        }
                        if(x + 1 < n && !visited[x + 1][y] && graph[x + 1][y] != '.') {
                            visited[x + 1][y] = true;
                            stack.emplace(x + 1, y);
                        }
                        if(y >= 1 && !visited[x][y - 1] && graph[x][y - 1] != '.') {
                            visited[x][y - 1] = true;
                            stack.emplace(x, y - 1);
                        }
                        if(y + 1 < n && !visited[x][y + 1] && graph[x][y + 1] != '.') {
                            visited[x][y + 1] = true;
                            stack.emplace(x, y + 1);
                        }
                    } while(!stack.empty());
                    if(count[0] + count[1] + count[2] + count[3] == 1) {
                        if(count[3] > 0) {
                            result = (result * 3) % MOD;
                        }
                    } else {
                        if(count[0] == 0 && (count[1] == 0 || count[2] == 0)) {
                            if(count[1] == 0 && count[2] == 0) {
                                result = (result * 2) % MOD;
                            }
                        } else {
                            result = 0;
                        }
                    }
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
