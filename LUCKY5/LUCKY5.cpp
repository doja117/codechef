#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string n; cin >> n; ) {
        int result = 0;
        for(auto c : n) {
            if(c != '4' && c != '7') {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
