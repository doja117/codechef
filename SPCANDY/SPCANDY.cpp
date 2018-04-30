#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(long long n, k; cin >> n >> k; cout << endl) {
        if(k == 0) {
            cout << "0 " << n;
        } else {
            cout << n / k << ' ' << n % k;
        }
    }
    return 0;
}
