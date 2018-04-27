#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; cout << endl) {
        long long a[n];
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sum /= n - 1;
        for(int i = 0; i < n; i++) {
            cout << sum - a[i] << ' ';
        }
    }
    return 0;
}
