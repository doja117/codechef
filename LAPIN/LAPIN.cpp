#include <iostream>
#include <map>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        map<char, int> m1, m2;
        for(int i = 0; i < s.size() / 2; i++) {
            m1[s[i]]++;
            m2[s.rbegin()[i]]++;
        }
        if(m1 == m2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
