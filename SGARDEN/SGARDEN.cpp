#include <iostream>
#include <vector>
#include <map>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, int n) {
    long long result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        x = x * x % MOD;
        n /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<bool> visited(n);
        long long result = 1;
        map<int, int> primes;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                int length = 1, next = a[i] - 1;
                while(next != i) {
                    visited[next] = true;
                    next = a[next] - 1;
                    length++;
                }
                map<int, int> factors;
                for(int i = 2; i * i <= length; i++) {
                    while(length % i == 0) {
                        factors[i]++;
                        length /= i;
                    }
                }
                if(length > 1) {
                    factors[length]++;
                }
                for(auto& i : factors) {
                    auto find = primes.find(i.first);
                    if(find == primes.end()) {
                        primes.emplace(i);
                    } else {
                        find->second = max(find->second, i.second);
                    }
                }
            }
        }
        for(auto& i : primes) {
            result = result * pow(i.first, i.second) % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
