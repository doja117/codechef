#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int a[n], result = 0;
        vector<bool> flag(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i < n; i++) {
            if(a[i] != a[i - 1]) {
                flag[i] = true;
                flag[i - 1] = true;
            }
        }
        for(int i = 0; i < n; i++) {
            result += flag[i];
        }
        cout << result << endl;
    }
    return 0;
}
