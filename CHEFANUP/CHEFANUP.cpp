#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long N, K, L; cin >> N >> K >> L; cout << endl) {
        int result[N];
        L--;
        for(int i = N - 1; i >= 0; i--) {
            result[i] = L % K + 1;
            L /= K;
        }
        for(int i = 0; i < N; i++) {
            cout << result[i] << ' ';
        }
    }
    return 0;
}
