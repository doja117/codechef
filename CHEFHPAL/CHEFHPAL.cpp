#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, a; cin >> n >> a; ) {
        int len;
        string result;
        result.reserve(n);
        if(a > 2) {
            len = 1;
            for(int i = 0; i < n; i++) {
                result.push_back('a' + i % a);
            }
        } else if(a == 1) {
            len = n;
            for(int i = 0; i < n; i++) {
                result.push_back('a');
            }
        } else {
            if(n < 3) {
                len = 1;
                for(int i = 0; i < n; i++) {
                    result.push_back('a' + i % a);
                }
            } else if(n < 5) {
                len = 2;
                auto t = "aabb";
                for(int i = 0; i < n; i++) {
                    result.push_back(t[i]);
                }
            } else if(n < 9) {
                len = 3;
                auto t = "aaababbb";
                for(int i = 0; i < n; i++) {
                    result.push_back(t[i]);
                }
            } else {
                len = 4;
                auto t = "abbabaabbaba";
                for(int i = 0; i < n; i++) {
                    result.push_back(t[i % 12]);
                }
            }
        }
        cout << len << ' ' << result << endl;
    }
    return 0;
}
