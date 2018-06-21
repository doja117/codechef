#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        int result[2] = {};
        for(int i = 0, empty = 0, last = '.'; i < s.size(); i++) {
            if(s[i] == 'B' || s[i] == 'A') {
                result[s[i] - 'A']++;
                if(last == s[i]) {
                    result[s[i] - 'A'] += empty;
                }
                empty = 0;
                last = s[i];
            } else {
                empty++;
            }
        }
        cout << result[0] << ' ' << result[1] << endl;
    }
    return 0;
}
