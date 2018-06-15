#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto current = a[0], count = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] == current) {
                count++;
            } else {
                count--;
            }
            if(count == 0) {
                current = a[i];
                count = 1;
            }
        }
        count = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == current) {
                count++;
            }
        }
        cout << max(count, (n + 1) / 2) << endl;
    }
    return 0;
}
