#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, k; cin >> n >> k; ) {
        string s;
        cin >> s;
        int result = 0;
        if(k == 1) {
            int first = 0, second = 0;
            for(int i = 0; i < n; i += 2) {
                if(s[i] != '1') {
                    first++;
                } else {
                    second++;
                }
            }
            for(int i = 1; i < n; i += 2) {
                if(s[i] != '0') {
                    first++;
                } else {
                    second++;
                }
            }
            char c;
            if(first < second) {
                c = '1';
                result = first;
            } else {
                c = '0';
                result = second;
            }
            for(int i = 0; i < n; i += 2) {
                s[i] = c;
            }
            for(int i = 1; i < n; i += 2) {
                s[i] = '1' - c + '0';
            }
        } else {
            for(int i = 1, same = 1; i < n; i++) {
                if(s[i] == s[i - 1]) {
                    same++;
                } else {
                    same = 1;
                }
                if(same > k) {
                    if(i + 1 < n && s[i] == s[i + 1]) {
                        s[i] = '1' - s[i] + '0';
                    } else {
                        s[i - 1] = '1' - s[i - 1] + '0';
                    }
                    same = 1;
                    result++;
                }
            }
        }
        cout << result << endl << s << endl;
    }
    return 0;
}
