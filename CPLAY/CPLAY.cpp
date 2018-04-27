#include <iostream>
using namespace std;

int main() {
    for(string s; cin >> s; cout << endl) {
        int a = 0, b = 0;
        for(int i = 0; i < 10; i += 2) {
            if(s[i] == '1') {
                a++;
            }
            if(a > b + (10 - i) / 2) {
                cout << "TEAM-A " << i + 1;
                goto next;
            } else if(a + (10 - i - 2) / 2 < b) {
                cout << "TEAM-B " << i + 1;
                goto next;
            }
            if(s[i + 1] == '1') {
                b++;
            }
            if(a > b + (10 - i - 2) / 2) {
                cout << "TEAM-A " << i + 2;
                goto next;
            } else if(a + (10 - i - 2) / 2 < b) {
                cout << "TEAM-B " << i + 2;
                goto next;
            }
        }
        if(a < b) {
            cout << "TEAM-B " << 10;
        } else if(b > a) {
            cout << "TEAM-A " << 10;
        } else {
            for(int i = 10; i < 20; i += 2) {
                if(s[i] == '1') {
                    a++;
                }
                if(s[i + 1] == '1') {
                    b++;
                }
                if(a < b) {
                    cout << "TEAM-B " << i + 2;
                    goto next;
                } else if(a > b) {
                    cout << "TEAM-A " << i + 2;
                    goto next;
                }
            }
            cout << "TIE";
        }
        next:
            ;
    }
    return 0;
}
