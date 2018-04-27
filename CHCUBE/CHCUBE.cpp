#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s[6]; cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5]; ) {
        string result = "NO\n";
        for(int i = 0; i < 6; i++) {
            for(int j = i + 1; j < 6; j++) {
                for(int k = j + 1; k < 6; k++) {
                    if(s[i] == s[j] && s[j] == s[k] && s[k] == s[i] && (i % 2 != 0 || i + 1 != j) && (j % 2 != 0 || j + 1 != k)) {
                        result = "YES\n";
                    }
                }
            }
        }
        cout << result;
    }
    return 0;
}
