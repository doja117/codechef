#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; cout << endl) {
        pair<int, int> pairs[m];
        for(int i = 0; i < m; i++) {
            cin >> pairs[i].first >> pairs[i].second;
        }
        vector<int> result {m - 1};
        set<int> used;
        used.emplace(pairs[m - 1].first);
        used.emplace(pairs[m - 1].second);
        for(int i = m - 2; i >= 0; i--) {
            if(used.find(pairs[i].first) == end(used) && used.find(pairs[i].second) == end(used)) {
                result.emplace_back(i);
                used.emplace(pairs[i].first);
                used.emplace(pairs[i].second);
            }
        }
        for(auto it = result.rbegin(); it != result.rend(); it++) {
            cout << *it << ' ';
        }
    }
    return 0;
}
