#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string s; cin >> s; ) {
        int w;
        for(w = 0; s[w] != 'W'; w++) {
        }
        if((w ^ (s.size() - w - 1)) == 0) {
            cout << "Chef\n";
        } else {
            cout << "Aleksa\n";
        }
    }
    return 0;
}
