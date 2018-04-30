#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, x; cin >> n >> x; cout << endl) {
        int sum = 0, min = 101;
        while(n > 0) {
            int a;
            cin >> a;
            sum += a;
            if(a < min) {
                min = a;
            }
            n--;
        }
        if((sum - min) / x == sum / x) {
            cout << -1;
        } else {
            cout << sum / x;
        }
    }
    return 0;
}
