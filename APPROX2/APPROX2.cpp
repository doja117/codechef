#include <iostream>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, k; cin >> n >> k; ) {
        int a[n];
        pair<int, int> result = {INT_MAX, 1};
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(abs(a[i] + a[j] - k) < result.first) {
                    result = {abs(a[i] + a[j] - k), 1};
                } else if(abs(a[i] + a[j] - k) == result.first) {
                    result.second++;
                }
            }
        }
        cout << result.first << ' ' << result.second << endl;
    }
    return 0;
}
