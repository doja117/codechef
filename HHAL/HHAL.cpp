#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        int result = 1;
        for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s.rbegin()[i]) {
                result = 2;
            }
        }
        cout << result << endl;
    }
    return 0;
}
