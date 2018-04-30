#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    long long a[N];
    for(int i = 0; cin >> a[i]; i++) {
    }
    if(K % 2 == 1) {
        K = 1;
    } else if(K != 0) {
        K = 2;
    }
    for(int j = 0; j < K; j++) {
        auto max = *max_element(a, a + N);
        for(int i = 0; i < N; i++) {
            a[i] = max - a[i];
        }
    }
    for(int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
