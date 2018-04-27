#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int SIZE = 10001;

int main() {
    int T;
    cin >> T;
    vector<bool> prime(SIZE, true);
    vector<int> primes;
    for(int i = 2; i * i < SIZE; i++) {
        if(prime[i]) {
            for(int j = i * i; j < SIZE; j += i) {
                prime[j] = false;
            }
        }
    }
    for(int i = 2; i < SIZE; i++) {
        if(prime[i]) {
            primes.emplace_back(i);
        }
    }
    for(int N; cin >> N; ) {
        int bucket[N], result = INT_MAX;
        for(int i = 0; i < N; i++) {
            cin >> bucket[i];
        }
        for(auto i : primes) {
            int last = 0, current = 0;
            for(auto j : bucket) {
                if(j > last) {
                    last = (j + i - 1) / i * i;
                }
                current += last - j;
            }
            result = min(result, current);
        }
        cout << result << endl;
    }
    return 0;
}
