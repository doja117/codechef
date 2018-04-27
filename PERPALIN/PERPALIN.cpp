#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, p; cin >> n >> p; ) {
        if(p == 1 || p == 2) {
            cout << "impossible\n";
            continue;
        }
        string result;
        result.push_back('a');
        for(int i = 1; i < p - 1; i++) {
            result.push_back('b');
        }
        result.push_back('a');
        for(int i = 0; i < n / p; i++) {
            cout << result;
        }
        cout << endl;
    }
    return 0;
}
