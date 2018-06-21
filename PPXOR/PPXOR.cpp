#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long n; cin >> n; ) {
        bitset<32> a[n];
        for(long long i = 0, j; i < n; i++) {
            cin >> j;
            a[i] = bitset<32>(j);
        }
        long long result = 0;
        for(long long i = 0, pow = 1; i < 32; i++, pow *= 2) {
            long long prefix = a[0][i], current = prefix;
            for(long long j = 1; j < n; j++) {
                if(a[j][i] == 1) {
                    prefix = j - prefix + 1;
                }
                current += prefix;
            }
            result += pow * current;
        }
        cout << result << endl;
    }
    return 0;
}
