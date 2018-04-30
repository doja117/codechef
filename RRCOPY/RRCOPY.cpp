#include <iostream>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        set<int> set;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            set.emplace(a);
        }
        cout << set.size() << endl;
    }
    return 0;
}
