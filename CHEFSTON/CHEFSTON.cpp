#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, K; cin >> N >> K; ) {
        int A[N], B[N];
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for(int i = 0; i < N; i++) {
            cin >> B[i];
        }
        long long result = 0;
        for(int i = 0; i < N; i++) {
            result = max(result, (long long)K / A[i] * B[i]);
        }
        cout << result << endl;
    }
    return 0;
}
