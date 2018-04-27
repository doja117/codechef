#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, k; cin >> n >> k; cout << endl) {
        int a[n];
        fill(a, a + n, 0);
        pair<int, int> b[k];
        for(int i = 0; i < k; i++) {
            cin >> b[i].first >> b[i].second;
            a[b[i].first] = 1;
            a[b[i].second] = -1;	
        }
        sort(b, b + k, [](pair<int, int>& left, pair<int, int>& right) {
            return left.second - left.first < right.second - right.first;
        });
        for(int i = 0; i < k; i++) {
            for(int j = b[i].first + 1, count = 1; j < b[i].second; j++) {
                if(a[j] == 0) {
                    if(count > 0) {
                        a[j] = -1;
                    } else {
                        a[j] = 1;
                    }
                }
                count = count + a[j];
            }
        }
        for(int i = 0; i < n; i++) {
            if(a[i] == -1) {
                cout << ')';
            } else {
                cout << '(';
            }
        }
    }
    return 0;
}
