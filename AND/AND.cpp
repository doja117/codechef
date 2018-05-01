#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long count[32] = {}, result = 0;
    for(int A; cin >> A; ) {
        bitset<32> bits(A);
        for(int i = 0; i < 32; i++) {
            if(bits[i]) {
                count[i]++;
            }
        }
    }
    for(int i = 0; i < 32; i++) {
        result += count[i] * (count[i] - 1) / 2 * (1 << i);
    }
    cout << result;
    return 0;
}
