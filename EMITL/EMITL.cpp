#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string s; cin >> s; ) {
        int L = 0, T = 0, I = 0, M = 0, E = 0;
        for(auto c : s) {
            if(c == 'L') {
                L++;
            } else if(c == 'T') {
                T++;
            } else if(c == 'I') {
                I++;
            } else if(c == 'M') {
                M++;
            } else if(c == 'E') {
                E++;
            }
        }
        if(L >= 2 && T >= 2 && I >= 2 && M >= 2 && E >= 2 || L == 2 && T == 2 && I == 2 && M == 2 && E == 1 && s.size() == 9) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
