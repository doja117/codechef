#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; cout << endl) {
        int s[n], result[n + 1];
        long long sum[n + 1];
        sum[0] = 0;
        result[0] = 0;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            sum[i + 1] = sum[i] + s[i];
            result[i + 1] = 0;
        }
        for(int i = 0; i < n; i++) {
            int begin = 0, end = i;
            while(begin < end) {
                auto mid = (begin + end) / 2;
                if(sum[i] - sum[mid + 1] <= s[i]) {
                    end = mid;
                } else {
                    begin = mid + 1;
                }
            }
            result[begin]++;
            begin = i, end = n - 1;
            while(begin < end) {
                auto mid = (begin + end + 1) / 2;
                if(sum[mid] - sum[i + 1] <= s[i]) {
                    begin = mid;
                } else {
                    end = mid - 1;
                }
            }
            result[begin + 1]--;
        }
        for(int i = 1; i < n; i++) {
            result[i] += result[i - 1];
        }
        for(int i = 0; i < n; i++) {
            cout << result[i] - 1 << ' ';
        }
    }
    return 0;
}
