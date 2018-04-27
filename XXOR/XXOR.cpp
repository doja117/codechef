#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    bitset<31> a[n];
    int bits[31][n + 1];
    for(int i = 0, t; i < n; i++) {
        cin >> t;
        a[i] = bitset<31>(t);
    }
    for(int i = 0; i < 31; i++) {
        bits[i][0] = 0;
        for(int j = 1; j <= n; j++) {
            bits[i][j] = bits[i][j - 1] + a[j - 1][i];
        }
    }
    for(int l, r; cin >> l >> r; ) {
        int length = r - l + 1;
        bitset<31> x;
        for(int i = 0; i < 31; i++) {
            int ones = bits[i][r] - bits[i][l - 1];
            if(ones >= length - ones) {
                x[i] = 0;
            } else {
                x[i] = 1;
            }
        }
        cout << x.to_ulong() << endl;
    }
    return 0;
}
