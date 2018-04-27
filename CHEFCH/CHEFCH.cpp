#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string s; cin >> s; ) {
        int c1 = 0, c2 = 0;
        for(int i = 0; i < s.size(); i += 2) {
            if(s[i] != '+') {
                c1++;
            } else {
                c2++;
            }
        }
        for(int i = 1; i < s.size(); i += 2) {
            if(s[i] != '-') {
                c1++;
            } else {
                c2++;
            }
        }
        cout << min(c1, c2) << endl;
    }
    return 0;
}
