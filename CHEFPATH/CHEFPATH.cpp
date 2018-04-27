#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(long long n, m; cin >> n >> m; ) {
        if(n > m) {
            swap(n, m);
        }
        if(n == 1 && m == 2 || n >= 2 && (n % 2 + m % 2 != 2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
