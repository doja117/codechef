#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        string s;
        cin >> s;
        long long one = 0;
        for(char c : s) {
            if(c == '1') {
                one++;
            }
        }
        cout << one * (one + 1) / 2 << endl;
    }
    return 0;
}
