#include <cstdio>
#include <algorithm>
using namespace std;

const long long SIZE = 5000001, MOD = 1000000007;

int main() {
    int T;
    scanf("%d", &T);
    bool prime[SIZE];
    fill(prime, prime + SIZE, 1);
    for(int i = 2; i * i < SIZE; i++) {
        if(prime[i]) {
            for(int j = i * i; j < SIZE; j += i) {
                prime[j] = false;
            }
        }
    }
    long long count[SIZE], result[SIZE];
    result[0] = 1;
    count[0] = 0;
    for(int i = 1; i < SIZE; i++) {
        count[i] = count[i - 1] + prime[i];
        result[i] = (result[i - 1] * count[i]) % MOD;
    }
    for(int N; scanf("%d", &N) > 0; printf("%d\n", result[N])) {
    }
    return 0;
}
