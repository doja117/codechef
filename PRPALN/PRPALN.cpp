#include <iostream>
using namespace std;

bool palindrome(string& s) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != s.rbegin()[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        string result = "NO\n";
        for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s.rbegin()[i]) {
                auto s1 = s.substr(0, i) + s.substr(i + 1), s2 = s.substr(0, s.size() - i - 1) + s.substr(s.size() - i);
                if(palindrome(s1) || palindrome(s2)) {
                    result = "YES\n";
                }
                break;
            }
        }
        if(palindrome(s)) {
            result = "YES\n";
        }
        cout << result;
    }
    return 0;
}
