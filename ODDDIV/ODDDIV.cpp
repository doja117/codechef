#include <iostream>
using namespace std;

const int SIZE = 100001;

int main() {
    long long T, f[SIZE];
    f[0] = 0;
    for(int i = 1; i < SIZE; i++) {
        f[i] = f[i - 1];
        int j = 1;
        while(j * j < i) {
            if(i % j == 0) {
                if(j % 2 == 1) {
                    f[i] += j;
                }
                if((i / j) % 2 == 1) {
                    f[i] += i / j;
                }
            }
            j++;
        }
        if(j * j == i && j % 2 == 1) {
            f[i] += j;
        }
    }
    cin >> T;
    for(int l, r; cin >> l >> r; ) {
        cout << f[r] - f[l - 1] << endl;
    }
    return 0;
}
