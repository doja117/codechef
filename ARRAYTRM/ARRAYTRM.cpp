#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, k; cin >> n >> k; ) {
        int arr[n], rem[k + 1];
        fill(rem, rem + k + 1, 0);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++) {
            rem[arr[i] % (k + 1)]++;
        }
        string result = "NO\n";
        for(int i = 0; i <= k; i++) {
            if(rem[i] >= n - 1) {
                result = "YES\n";
                break;
            }
        }
        cout << result;
    }
    return 0;
}
