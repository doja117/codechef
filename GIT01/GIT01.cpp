#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, m; cin >> n >> m; ) {
        int result[2] = {};
        while(n > 0) {
            string s;
            cin >> s;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == 'R') {
                    if((i + n) % 2 == 1) {
                        result[0] += 5;
                    } else {
                        result[1] += 5;
                    }
                } else {
                    if((i + n) % 2 == 0) {
                        result[0] += 3;
                    } else {
                        result[1] += 3;
                    }
                }
            }
            n--;
        }
        cout << min(result[0], result[1]) << endl;
    }
    return 0;
}
