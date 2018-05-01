#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], dp[n], result = 0;
    for(int i = 0; cin >> a[i]; i++) {
    }
    dp[0] = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < dp[result]) {
            result++;
            dp[result] = a[i];
        } else {
            int low = 0, high = result;
            while(low < high) {
                auto mid = (low + high) / 2;
                if(dp[mid] <= a[i]) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            dp[low] = a[i];
        }
    }
    cout << result + 1;
    return 0;
}
