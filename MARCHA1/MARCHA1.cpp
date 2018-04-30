#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, m; cin >> n >> m; ) {
        int banknote[n];
        for(int i = 0; i < n; i++) {
            cin >> banknote[i];
        }
        string result = "No\n";
        for(int i = 1; i < (1 << n); i++) {
            int sum = 0;
            for(int j = i, k = 0; j > 0; j /= 2, k++) {
                if(j % 2 == 1) {
                    sum += banknote[k];
                }
            }
            if(sum == m) {
                result = "Yes\n";
            }
        }
        cout << result;
    }
    return 0;
} 
