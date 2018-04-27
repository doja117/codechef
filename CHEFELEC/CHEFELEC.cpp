#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        string s;
        cin >> s;
        int x[n];
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }
        long long result = x[n - 1] - x[0]; 
        int i = 0;
        while(i < n && s[i] == '0') {
            i++;
        }
        while(i < n) {
            int j = i + 1, largest = 0;
            while(j < n && s[j] == '0') {
                largest = max(largest, x[j] - x[j - 1]);
                j++;
            }
            if(j < n) {
                result -= max(largest, x[j] - x[j - 1]);
            }
            i = j;
        }
        cout << result << endl;
    }
    return 0;
}
