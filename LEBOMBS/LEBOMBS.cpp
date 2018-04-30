#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        string s;
        cin >> s;
        int result = 0;
        if(n > 1) {
            if(s[0] == '0' && s[1] == '0') {
                result++;
            }
            if(s[n - 1] == '0' && s[n - 2] == '0') {
                result++;
            }
        } else {
            if(s[0] == '0') {
                result++;
            }
        }
        for(int i = 1; i < n - 1; i++) {
            if(s[i] == '0' && s[i - 1] == '0' && s[i + 1] == '0') {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
