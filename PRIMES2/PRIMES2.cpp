#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 1000000;

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
    for(int n; cin >> n; ) {
        if(n == 0) {
            break;
        }
        for(int i = 0; i < primes.size(); i++) {
            long long p2 = primes[i] * primes[i];
            if(p2 >= n) {
                break;
            }
            for(int j = 0; j < primes.size(); j++) {
                long long p3 = primes[j] * primes[j] * primes[j];
                if(p2 + p3 >= n) {
                    break;
                }
                if(prime[n - p2 - p3]) {
                    cout << n - p2 - p3 << ' ' << primes[i] << ' ' << primes[j] << ' ' << endl;
                    goto next;
                }
            }
        }
        cout << 0 << ' ' << 0 << ' ' << 0 << endl;
        next:
        ;
    }
    return 0;
}
