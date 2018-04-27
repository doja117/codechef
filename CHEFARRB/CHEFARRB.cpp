#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(unsigned int N, K; cin >> N >> K; ) {
        unsigned int A[N];
        for(int i = 0; i != N; i++) {
            cin >> A[i];
        }
        long long result = 0;
        int bits[32] = {};
        bitset<32> current(0);
        for(int begin = 0, end = 0; begin < N; ) {
            while(end < N && current.to_ulong() < K) {
                current |= A[end];
                bitset<32> bit(A[end]);
                for(int j = 0; j < 32; j++) {
                    bits[j] += bit[j];
                }
                end++;
            }
            if(current.to_ulong() >= K) {
                result += N - end + 1;
            }
            bitset<32> bit(A[begin]);
            for(int j = 0; j < 32; j++) {
                bits[j] -= bit[j];
                current[j] = bits[j];
            }
            begin++;
        }
        cout << result << endl;
    }
    return 0;
}
