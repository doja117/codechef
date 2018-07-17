#include <iostream>
using namespace std;

const int automata[][4] = {{1, 2, 5, 8}, {1, 2, 5, 8}, {3, 2, 4, 7}, {3, 4, 4, 4}, {4, 4, 4, 4}, {3, 4, 5, 6}, {3, 2, 4, 7}, {3, 4, 5, 6}, {3, 2, 5, 8}};

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
        if(state != 4) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
