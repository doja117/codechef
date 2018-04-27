#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long N, K; cin >> N >> K; ) {
        string s;
        cin >> s;
        int prefix[N], suffix[N];
        prefix[0] = 0;
        for(long long i = 1; i < N; i++) {
            if(s[i - 1] == 'b') {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
        }
        suffix[N - 1] = 0;
        for(long long i = N - 2; i >= 0; i--) {
            if(s[i + 1] == 'b') {
                suffix[i] = suffix[i + 1] + 1;
            } else {
                suffix[i] = suffix[i + 1];
            }
        }
        long long result = 0;
        for(long long i = 0; i < N; i++) {
            if(s[i] == 'a') {
                result += K * (prefix[i] * (K - 1) + suffix[i] * (K + 1)) / 2;
            }
        }
        cout << result << endl;
    }
    return 0;
}
