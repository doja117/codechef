#include <iostream>
#include <vector>
using namespace std;

int length(int n) {
    int result = 0;
    while(n > 0) {
        result++;
        n /= 2;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for(int N, K; cin >> N >> K; ) {
        vector<int> bucket[32];
        for(int i = 0; i < N; i++) {
            int A;
            cin >> A;
            bucket[length(A)].emplace_back(A);
        }
        for(int i = 31; i > 0; i--) {
            if(!bucket[i].empty()) {
                auto front = bucket[i].front();
                K = max(K, K ^ front);
                for(int j = 1; j < bucket[i].size(); j++) {
                    auto t = bucket[i][j] ^ front;
                    bucket[length(t)].emplace_back(t);
                }
            }
        }
        cout << K << endl;
    }
    return 0;
}
