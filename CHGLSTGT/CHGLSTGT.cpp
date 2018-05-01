#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        string s;
        cin >> s;
        vector<bool> palindrome[s.size()];
        fill(palindrome, palindrome + s.size(), vector<bool>(s.size() + 1));
        for(int i = 0; i < s.size(); i++) {
            palindrome[i][i] = true;
            palindrome[i][i + 1] = true;
        }
        for(int i = 2; i <= s.size(); i++) {
            for(int j = 0; j + i <= s.size(); j++) {
                if(s[j] == s[j + i - 1]) {
                    palindrome[j][j + i] = palindrome[j + 1][j + i - 1];
                } else {
                    palindrome[j][j + i] = false;
                }
            }
        }
        int g[s.size()];
        g[0] = 1;
        for(int i = 1; i < s.size(); i++) {
            if(palindrome[0][i + 1]) {
                g[i] = 1;
            } else {
                g[i] = n;
            }
            for(int j = i; j > 0; j--) {
                if(palindrome[j][i + 1]) {
                    g[i] = min(g[i], g[j - 1] + 1);
                }
            }
        }
        cout << g[n - 1] << endl;
    }
    return 0;
}
