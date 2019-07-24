#include <iostream>
using namespace std;

int main() {
    int N, Q, result = 0;
    cin >> N >> Q;
    int A[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        while (A[i] != i) {
            swap(A[i], A[A[i]]);
            result++;
        }
    }
    result = result % 2;
    for (int x, y; cin >> x >> y; ) {
        result = 1 - result;
        cout << result << '\n';
    }
    return 0;
}
