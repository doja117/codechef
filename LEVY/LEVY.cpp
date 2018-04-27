#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10000;

int main() {
    vector<bool> prime(SIZE, true);
    prime[1] = false;
    for(int i = 2; i * i < SIZE; i++) {
        if(prime[i]) {
            for(int j = i * i; j < SIZE; j += i) {
            prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for(int i = 2; i < SIZE; i++) {
        if(prime[i]) {
            primes.emplace_back(i);
        }
    }
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        int result = 0;
        for(int i = 0; true; i++) {
            auto r = n - 2 * primes[i];
            if(r <= 0) {
                break;
            }
            if(prime[r]) {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
