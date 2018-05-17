#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, p; cin >> n >> p; ) {
        int cakewalk = 0, hard = 0;
        for(int i = 0, a; i < n; i++) {
            cin >> a;
            if(a >= p / 2) {
                cakewalk++;
            } else if(a <= p / 10) {
                hard++;
            }
        }
        if(cakewalk != 1 || hard != 2) {
            cout << "no\n";
        } else {
            cout << "yes\n";
        }
    }
    return 0;
}
