#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 1000004;

int main() {
    vector<bool> primes(SIZE, true);
    for(int i = 2; i * i < SIZE; i++) {
        if(primes[i]) {
            for(int j = i * i; j < SIZE; j += i) {
                primes[j] = false;
            }
        }
    }
    int T;
    cin >> T;
    for(int x, y; cin >> x >> y; ) {
        for(int i = x + y + 1; ; i++) {
            if(primes[i]) {
                cout << i - x - y << endl;
                break;
            }
        }
    }
    return 0;
}
