#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, K; cin >> N >> K; ) {
        int B[K + 1];
        fill(B + 1, B + K + 1, 0);
        vector<int> A[N];
        for(int i = 0; i < N; i++) {
            int P;
            cin >> P;
            for(int j = 0; j < P; j++) {
                int k;
                cin >> k;
                A[i].emplace_back(k);
                B[k]++;
            }
        }
        bool flag = false;
        for(int i = 1; i <= K; i++) {
            if(B[i] == 0) {
                flag = true;
            }
        }
        if(flag) {
            cout << "sad\n";
            continue;
        }
        flag = false;
        for(int i = 0; i < N; i++) {
            bool extra = true;
            for(auto j : A[i]) {
                if(B[j] == 1) {
                    extra = false;
                }
            }
            if(extra) {
                flag = true;
            }
        }
        if(flag) {
            cout << "some\n";
        } else {
            cout << "all\n";
        }
    }
    return 0;
}
