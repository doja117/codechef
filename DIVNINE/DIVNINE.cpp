#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string N; cin >> N; ) {
        int sum = 0;
        for(auto i : N) {
            sum += i - '0';
        }
        if(sum >= 9 || N.size() == 1) {
            cout << min((9 - sum % 9) % 9, sum % 9) << endl;
        } else {
            cout << 9 - sum << endl;
        }
    }
    return 0;
}
