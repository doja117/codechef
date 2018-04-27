#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int maxK = 5, SIZE = 100001;

int main() {
    int T, minprime[SIZE], sum[maxK][SIZE];
    fill(minprime, minprime + SIZE, 0);
    for(int i = 2; i < SIZE; i++) {
        if(minprime[i] == 0) {
            for(int j = i; j < SIZE; j += i) {
                minprime[j] = i;
            }
        }
    }
    for(int i = 0; i < maxK; i++) {
        sum[i][0] = 0;
        sum[i][1] = 0;
    }
    for(int i = 2; i < SIZE; i++) {
        set<int> factors;
        for(int j = i; j > 1; j /= minprime[j]) {
            factors.emplace(minprime[j]);
        }
        for(int j = 0; j < maxK; j++) {
            sum[j][i] = sum[j][i - 1];
        }
        if(factors.size() <= maxK) {
            sum[factors.size() - 1][i]++;
        }
    }
    cin >> T;
    for(int A, B, K; cin >> A >> B >> K; ) {
        cout << sum[K - 1][B] - sum[K - 1][A - 1] << endl;
    }
    return 0;
}
