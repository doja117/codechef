#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    int A[N], B[N];
    pair<int, int> C[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; cin >> B[i]; i++) {
    }
    for(int i = 0; i < N; i++) {
        C[i] = {A[i] - B[i], i};
    }
    sort(C, C + N, greater<pair<int, int>>());
    int i = 0, result = 0;
    for(; i < min(N, X); i++) {
        if(C[i].first >= 0 || Y < N - i) {
            result += A[C[i].second];
        } else {
            break;
        }
    }
    for(; i < N; i++) {
        result += B[C[i].second];
    }
    cout << result;
    areturn 0;
}
