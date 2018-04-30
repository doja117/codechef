#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        if(n % 4 == 1) {
            cout << "ALICE\n";
        } else {
            cout << "BOB\n";
        }
    }
    return 0;
}
