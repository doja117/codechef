#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int k; cin >> k; cout << endl) {
        cout << '3';
        if(k > 0) {
            cout << '.';
        }
        for(int i = 46870, j = 33102; k > 0; k--) {
            auto t = i / j;
            i = (i - t * j) * 10;
            cout << t;
        }
    }
    return 0;
}
