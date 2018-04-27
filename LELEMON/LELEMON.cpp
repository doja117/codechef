#include <iostream>
#include <list>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, m; cin >> n >> m; ) {
        int p[m], result = 0;
        for(int i = 0; i < m; i++) {
            cin >> p[i];
        }
        list<int> lemon[n];
        for(int i = 0, c, v; i < n; i++) {
            for(cin >> c; c > 0; c--) {
                cin >> v;
                lemon[i].emplace_back(v);
            }
        }
        for(int i = 0; i < n; i++) {
            lemon[i].sort();
        }
        for(int i = 0; i < m; i++) {
            if(!lemon[p[i]].empty()) {
                result += lemon[p[i]].back();
                lemon[p[i]].pop_back();
            }
        }
        cout << result << endl;
    }
    return 0;
}
