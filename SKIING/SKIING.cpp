#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; ) {
        pair<int, int> a[n * m];
        int* h[n];
        vector<bool> visited[n];
        for(int i = 0; i < n; i++) {
            h[i] = new int[m];
            visited[i].resize(m);
            for(int j = 0; j < m; j++) {
                cin >> h[i][j];
                a[i * m + j] = {i, j};
            }
        }
        auto cmp = [&h](pair<int, int>& left, pair<int, int>& right) {
            return h[left.first][left.second] > h[right.first][right.second];
        };
        sort(a, a + n * m, cmp);
        int result = 0;
        for(int i = 0; i < n * m; i++) {
            int x = a[i].first, y = a[i].second;
            if(!visited[x][y]) {
                result++;
                visited[x][y] = true;
                stack<pair<int, int>> stack;
                stack.emplace(x, y);
                do {
                    auto x = stack.top().first, y = stack.top().second;
                    stack.pop();
                    if(x > 0 && h[x][y] >= h[x - 1][y] && !visited[x - 1][y]) {
                        visited[x - 1][y] = true;
                        stack.emplace(x - 1, y);
                    }
                    if(x + 1 < n && h[x][y] >= h[x + 1][y] && !visited[x + 1][y]) {
                        visited[x + 1][y] = true;
                        stack.emplace(x + 1, y);
                    }
                    if(y > 0 && h[x][y] >= h[x][y - 1] && !visited[x][y - 1]) {
                        visited[x][y - 1] = true;
                        stack.emplace(x, y - 1);
                    }
                    if(y + 1 < m && h[x][y] >= h[x][y + 1] && !visited[x][y + 1]) {
                        visited[x][y + 1] = true;
                        stack.emplace(x, y + 1);
                    }
                } while(!stack.empty());
            }
        }
        cout << result << endl;
    }
    return 0;
}
