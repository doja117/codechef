#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int g; cin >> g; ) {
        for(int i = 0; i < g; i++) {
            int I, N, Q, result;
            cin >> I >> N >>Q;
            if(I != Q) {
                result = (N + 1) / 2;
            } else {
                result = N / 2;
            }
            cout << result << endl;
        }
    }
    return 0;
}
