#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    sort(a, a + n);
    long long result = 0, sum = 0;
    for(int i = n - 1; i >= 0; i--) {
        long long t = a[i] + sum;
        if(t < 0) {
            if(i + 1 > x) {
                result += x * -t;
                sum -= t;
            } else {
                result -= t;
            }
        }
    }
    cout << result;
    return 0;
}
