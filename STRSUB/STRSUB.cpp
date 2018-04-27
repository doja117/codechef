#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, k, q; cin >> n >> k >> q; ) {
        string s;
        cin >> s;
        long long front[n + 1], back[n + 1];
        front[0] = 0;
        int count[2] = {};
        for(int i = 1, j = 0; i <= n; i++) {
            while(count[0] <= k && count[1] <= k && j <= n) {
                j++;
                if(j > n) {
                    break;
                }
                count[s[j - 1] - '0']++;
            }
            front[i] = j;
            count[s[i - 1] - '0']--;
        }
        back[n] = n;
        for(int i = n - 1, j = n; i > 0; i--) {
            while(j > 0 && front[j] > i) {
                j--;
            }
            back[i] = j;
        }
        for(int i = 1; i <= n; i++) {
            front[i] += front[i - 1];
        }
        for(long long l, r; q > 0; q--) {
            cin >> l >> r;
            long long k = max(l - 1, back[r]);
            cout << front[k] - front[l - 1] + (r - k) * (r + 1) - (r * (r + 1) - l * (l - 1)) / 2 << endl;
        }
    }
    return 0;
}
