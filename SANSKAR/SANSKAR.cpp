#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, k; cin >> n >> k; ) {
        long long sum = 0, posused[n], a[n];
        bool flag = 0;
        fill(posused, posused + n, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if(a[i] > 0) {
                flag = 1;
            }
        }
        if(sum % k != 0) {
            cout << "no\n";
        } else {
            if(!flag) {
                if(k <= n) {
                    cout << "yes\n";
                } else {
                    cout << "no\n";
                }
            } else {
                int val = 0;
                for(int i = 0; i < (1 << n); i++) {
                    long long current = 0;
                    for(int j = 0; j < n; j++) {
                        if(((1 << j) & i) && posused[j] == 0) {
                            current += a[j];
                        }
                    }
                    if(current == sum / k) {
                        for(int j = 0; j < n; j++) {
                            if((1 << j) & i) {
                                posused[j] = 1;
                            }
                        }
                        val++;
                    }
                }
                if(val == k) {
                    cout << "yes\n";
                } else {
                    cout << "no\n";
                }
            }
        }
    }
    return 0;
}
