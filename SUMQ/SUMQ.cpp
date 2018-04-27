#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    for(int p, q, r; cin >> p >> q >> r; ) {
        int A[p], B[q], C[r];
        for(int i = 0; i < p; i++) {
            cin >> A[i];
        }
        for(int i = 0; i < q; i++) {
            cin >> B[i];
        }
        for(int i = 0; i < r; i++) {
            cin >> C[i];
        }
        sort(A, A + p);
        sort(B, B + q);
        sort(C, C + r);
        int prefixA[p + 1], prefixC[r + 1];
        prefixA[0] = 0;
        prefixC[0] = 0;
        for(int i = 0; i < p; i++) {
            prefixA[i + 1] = (prefixA[i] + A[i]) % MOD;
        }
        for(int i = 0; i < r; i++) {
            prefixC[i + 1] = (prefixC[i] + C[i]) % MOD;
        }
        long long result = 0;
        for(int i = 0, j = -1, k = -1; i < q; i++) {
            while(j + 1 < p && A[j + 1] <= B[i]) {
                j++;
            }
            while(k + 1 < r && C[k + 1] <= B[i]) {
                k++;
            }
            if(j >= 0 && k >= 0) {
                result = (result + (prefixA[j + 1] + (long long)(j + 1) * B[i] % MOD) * (prefixC[k + 1] + (long long)(k + 1) * B[i] % MOD)) % MOD;
            }
        }
        cout << result << endl;
    }
    return 0;
}
