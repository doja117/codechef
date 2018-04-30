#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string s; cin >> s; ) {
        int result = s.size() + 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i - 1] <= s[i]) {
                result += s[i] - s[i - 1];
            } else {
                result += s[i] - s[i - 1] + 26;
            }
        }
        if(result <= s.size() * 11) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
