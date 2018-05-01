#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int a[n];
    set<int> set[6];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j : {2, 3, 5}) {
            if(a[i] % j == 0) {
                set[j].emplace(i);
            }
        }
    }
    cin >> m;
    for(int t; cin >> t; ) {
        int l, r, p;
        switch(t) {
            case 1:
                cin >> l >> r >> p;
                l--;
                r--;
                for(auto it = set[p].lower_bound(l); it != set[p].end() && *it <= r; ) {
                    a[*it] /= p;
                    if(a[*it] % p != 0) {
                        it = set[p].erase(it);
                    } else {
                        it++;
                    }
                }
                break;
            case 2:
                cin >> l >> r;
                l--;
                a[l] = r;
                for(int j : {2, 3, 5}) {
                    if(a[l] % j == 0) {
                        set[j].emplace(l);
                    } else {
                        set[j].erase(l);
                    }
                }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
