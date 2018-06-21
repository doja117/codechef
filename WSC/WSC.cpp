#include <iostream>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; ) {
        set<int> node;
        set<pair<int, int>> edge;
        for(int x, y, i = 0; i < m; i++) {
            cin >> x >> y;
            node.emplace(x);
            node.emplace(y);
            edge.emplace(x, y);
        }
        if(node.size() <= 2 || node.size() == 3 && edge.size() <= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
