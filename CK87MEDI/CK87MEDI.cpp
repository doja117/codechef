#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, K; cin >> N >> K; ) {
        int A[N];
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A, A + N);
        cout << A[(N + K) / 2] << endl;
    }
    return 0;
}
