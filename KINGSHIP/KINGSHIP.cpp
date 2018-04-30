#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        long long a[n], result = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto min = distance(a, min_element(a, a + n));
        for(int i = 0; i < n; i++) {
            if(i != min) {
                result += a[i] * a[min];
            }
        }
        cout << result << endl;
    }
    return 0;
}
