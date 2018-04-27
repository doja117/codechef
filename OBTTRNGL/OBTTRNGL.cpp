#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long k, A, B; cin >> k >> A >> B; cout << endl) {
        if(B < A) {
            swap(A, B);
        }
        B -= A;
        if(2 * B == k) {
            cout << 0;
        } else {
            cout << min(B - 1, k - B - 1);
        }
    }
    return 0;
}
