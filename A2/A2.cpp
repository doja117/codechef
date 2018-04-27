#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int k; cin >> k; ) {
        string result = "Yes\n";
        int i = 1;
        for(int j; k > 0; k--) {
            cin >> j;
            if(j > i) {
                result = "No\n";
            }
            i = (i - j) * 2;
        }
        if(i != 0) {
            result = "No\n";
        }
        cout << result;
    }
    return 0;
}
