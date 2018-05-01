#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 1000001;

int main() {
    int T;
    cin >> T;
    int minprime[SIZE];
    fill(minprime, minprime + SIZE, 0);
    for(int i = 2; i < SIZE; i++) {
        if(minprime[i] == 0) {
            for(int j = i; j < SIZE; j += i) {
                minprime[j] = i;
            }
        }
    }
    for(int N; cin >> N; ) {
        int A[N], result = -1, count = 0;
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        char primes[SIZE];
        fill(primes, primes + SIZE, 0);
        for(int begin = 0, end = 0; end < N; end++) {
            for(int j = A[end]; j > 1; ) {
                primes[minprime[j]]++;
                if(primes[minprime[j]] > 1) {
                    count++;
                }
                auto p = minprime[j];
                while(j % p == 0 && j > 1) {
                    j /= p;
                }
            }
            while(count > 0) {
                for(int j = A[begin]; j > 1; ) {
                    primes[minprime[j]]--;
                    if(primes[minprime[j]] == 1) {
                        count--;
                    }
                    auto p = minprime[j];
                    while(j % p == 0 && j > 1) {
                        j /= p;
                    }
                }
                begin++;
            }
            if(end > begin) {
                result = max(result, end - begin + 1);
            }
        }
        cout << result << endl;
    }
    return 0;
}
