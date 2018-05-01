#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int woman[n][n], man[n][n], accept[n], propose[n];
        stack<int> stack;
        for(int i = 0, k; i < n; i++) {
            cin >> k;
            for(int j = 0; j < n; j++) {
                cin >> k;
                woman[i][k - 1] = j;
            }
        }
        for(int i = 0, k; i < n; i++) {
            cin >> k;
            for(int j = 0; j < n; j++) {
                cin >> man[i][j];
            }
            stack.emplace(i);
        }
        fill(accept, accept + n, -1);
        fill(propose, propose + n, 0);
        do {
            auto top = stack.top();
            stack.pop();
            while(true) {
                int propose_to = man[top][propose[top]] - 1;
                propose[top]++;
                if(accept[propose_to] == -1) {
                    accept[propose_to] = top;
                } else if(woman[propose_to][accept[propose_to]] > woman[propose_to][top]) {
                    stack.emplace(accept[propose_to]);
                    accept[propose_to] = top;
                } else {
                    continue;
                }
                break;
            }
        } while(!stack.empty());
        for(int i = 0; i < n; i++) {
            cout << accept[i] + 1 << ' ' << i + 1 << endl;
        }
    }
    return 0;
}
