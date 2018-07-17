#include <iostream>
using namespace std;

const int automata[][4] = {{0, 1, 4, 7}, {2, 1, 3, 6}, {2, 3, 3, 3}, {3, 3, 3, 3}, {2, 3, 4, 5}, {2, 1, 3, 6}, {2, 3, 4, 5}, {2, 1, 4, 7}};

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        string s1, s2;
        cin >> s1 >> s2;
        int state = 0;
        for(int i = 0; i < n; i++) {
            int type;
            if(s1[i] == '.') {
                if(s2[i] == '.') {
                    type = 0;
                } else {
                    type = 1;
                }
            } else {
                if(s2[i] == '.') {
                    type = 2;
                } else {
                    type = 3;
                }
            }
            state = automata[state][type];
        }
        if(state != 3) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
