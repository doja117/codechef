#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        int result[2] = {};;
        for(int i = 0, empty = 0, last = -1; i < s.size(); i++) {
            if(s[i] == 'A') {
                result[0]++;
                if(last == 0) {
                    result[0] += empty;
                }
                empty = 0;
                last = 0;
            } else if(s[i] == 'B') {
                result[1]++;
                if(last == 1) {
                    result[1] += empty;
                }
                empty = 0;
                last = 1;
            } else {
                empty++;
            }
        }
        cout << result[0] << ' ' << result[1] << endl;
    }
    return 0;
}
