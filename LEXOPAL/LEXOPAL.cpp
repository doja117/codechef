#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string s; cin >> s; cout << s) {
        for(int i = 0; i <= s.size() / 2; i++) {
            if(s[i] == '.') {
                if(s.rbegin()[i] == '.') {
                    s[i] = 'a';
                    s.rbegin()[i] = 'a';
                } else {
                    s[i] = s.rbegin()[i];
                }
            } else if(s.rbegin()[i] == '.') {
                s.rbegin()[i] = s[i];
            } else if(s[i] != s.rbegin()[i]) {
                s = "-1";
                break;
            }
        }
        s.push_back('\n');
    }
    return 0;
}
