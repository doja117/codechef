#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long N, K; cin >> N >> K; ) {
        long long A[N], B[N], m = 0, sum = 0;
        for(long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        for(long long i = 0; i < N; i++) {
            cin >> B[i];
            m = max(m, abs(B[i]));
            sum += A[i] * B[i];
        }
        cout << sum + K * m << endl;
    }
    return 0;
}
