#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int SIZE = 10000000;

int main() {
    int prime[SIZE], T;
    fill(prime, prime + SIZE, 1);
    prime[0] = 0;
    prime[1] = 0;
    for(long long i = 2, j = 1; i < SIZE; i++) {
        if(prime[i]) {
            prime[i] = j;
            j++;
            for(long long k = i * i; k < SIZE; k += i) {
                prime[k] = 0;
            }
        }
    }
    cin >> T;
    for(int n; cin >> n; ) {
        int s[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> s[i][j];
            }
        }
        long long result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(s[i][j] == -1) {
                    continue;
                }
                if(prime[s[i][j]] != 0) {
                    result += prime[s[i][j]] - 1;
                    s[i][j] = -1;
                } else {
                    bool even = 1 - s[i][j] % 2;
                    result += s[i][j] / 2 + 2 * (s[i][j] % 2);
                    s[i][j] = -1;
                    stack<pair<int, int>> stack;
                    stack.emplace(i, j);
                    do {
                        auto x = stack.top().first, y = stack.top().second;
                        stack.pop();
                        if(x >= 1 && s[x - 1][y] != -1 && !prime[s[x - 1][y]] && (even ^ (s[x - 1][y] % 2))) {
                            s[x - 1][y] = -1;
                            stack.emplace(x - 1, y);
                        }
                        if(x + 1 < n && s[x + 1][y] != -1 && !prime[s[x + 1][y]] && (even ^ (s[x + 1][y] % 2))) {
                            s[x + 1][y] = -1;
                            stack.emplace(x + 1, y);
                        }
                        if(y >= 1 && s[x][y - 1] != -1 && !prime[s[x][y - 1]] && (even ^ (s[x][y - 1] % 2))) {
                            s[x][y - 1] = -1;
                            stack.emplace(x, y - 1);
                        }
                        if(y + 1 < n && s[x][y + 1] != -1 && !prime[s[x][y + 1]] && (even ^ (s[x][y + 1] % 2))) {
                            s[x][y + 1] = -1;
                            stack.emplace(x, y + 1);
                        }
                    } while(!stack.empty());
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
