#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, k; cin >> n >> k; ) {
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string result = "NO\n";
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int current = 0;
                for(int k = i; k <= j; k++) {
                    if(a[k] % 2 == 0) {
                        current++;
                    }
                }
                if(current == k) {
                    result = "YES\n";
                }
            }
        }
        cout << result;
    }
    return 0;
}
