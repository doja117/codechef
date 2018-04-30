#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, K; cin >> N; ) {
        pair<int, int> A[N];
        for(int i = 1; i <= N; i++) {
            cin >> A[i - 1].first;
            A[i - 1].second = i;
        }
        cin >> K;
        sort(A, A + N);
        for(int i = 0; i < N; i++) {
            if(A[i].second == K) {
                cout << i + 1 << endl;
            }
        }
    }
    return 0;
}
