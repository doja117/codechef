#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        int c[n];
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        string result = "No\n";
        int same = 1;
        for(int i = 1; i < n; i++) {
            if(c[i] == c[i - 1]) {
                same++;
            } else {
                if(same >= 3) {
                    result = "Yes\n";
                }
                same = 1;
            }
        }
        if(same >= 3) {
            result = "Yes\n";
        }
        cout << result;
    }
    return 0;
}
