#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, k; cin >> n >> k; ) {
        int result = 0, prefix[n + 2];
        string s;
        cin >> s;
        fill(prefix, prefix + n + 2, 0);
        for(int i = 1; i <= n; i++) {
            prefix[i] += prefix[i - 1];
            if((prefix[i] + (s[i - 1] == 'R')) % 2 == 1) {
                prefix[i]++;
                prefix[min(i + k - 1, n) + 1]--;
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
