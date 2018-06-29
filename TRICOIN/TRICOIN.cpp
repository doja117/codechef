#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long n; cin >> n; ) {
        long long begin = 0, end = n;
        while(begin < end) {
            auto mid = (begin + end + 1) / 2;
            if(mid * (mid + 1) / 2 <= n) {
                begin = mid;
            } else {
                end = mid - 1;
            }
        }
        cout << begin << endl;
    }
    return 0;
}
