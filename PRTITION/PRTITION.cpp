#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(long long x, n; cin >> x >> n; ) {
        long long left = 0, right = 0;
        string result;
        for(long long i = n; i >= 1; i--) {
            if(i != x) {
                if(left < right) {
                    left += i;
                    result.push_back('0');
                } else {
                    result.push_back('1');
                    right += i;
                }
            } else {
                result.push_back('2');
            }
        }
        if(abs(left - right) == 2 && n >= 4) {
            result[0] = 1 - (result[0] - '0') + '0';
            result[1] = 1 - (result[1] - '0') + '0';
            left = min(left, right) + 1;
            right = left;
        }
        if(left == right) {
            reverse(result.begin(), result.end());
            result.push_back('\n');
            cout << result;
        } else {
            cout << "impossible\n";
        }
    }
    return 0;
}
