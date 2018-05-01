#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        int t = 0;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            t = t ^ a;
        }
        if(t == 0 || n % 2 == 0) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
    return 0;
}
