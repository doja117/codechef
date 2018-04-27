
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string n; cin >> n; ) {
        int result = -1, sum = 0;
        for(auto c : n) {
            sum += c - '0';
        }
        for(int i = 0; i < n.size(); i++) {
            int current = sum - (n[i] - '0');
            if(current % 3 == 0) {
                if(n.rbegin()[i == n.size() - 1] % 2 == 0) {
                    result = i;
                    if(i + 1 < n.size() && n[i] < n[i + 1]) {
                        break;
                    }
                }
            }
        }
        if(result == -1) {
            cout << "-1\n";
        } else {
            cout << n.substr(0, result) + n.substr(result + 1, string::npos) << endl;
        }
    }
    return 0;
}
