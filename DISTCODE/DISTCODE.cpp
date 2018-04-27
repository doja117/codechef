#include <iostream>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        set<pair<char, char>> set;
        for(int i = 1; i < s.size(); i++) {
            set.emplace(s[i - 1], s[i]);
        }
        cout << set.size() << endl;
    }
    return 0;
}
