#include <iostream>
using namespace std;

int dp[1000001];

int main(){
    int n, q;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        int left = 0, right = 0;
        for(int j = i - 1; j >= 0 && a[j] > a[i]; j--) {
            left++;
        }
        for(int j = i + 1; j < n && a[j] >= a[i]; j++) {
            right++;
        }
        dp[a[i]] += (left + 1) * (right + 1) ;
    }
    cin >> q;
    for(int x; cin >> x; ) {
        cout << dp[x] << endl;
    }
    return 0 ;
}
