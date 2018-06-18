#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; cout << endl) {
        int mod[4] = {}, sum = 0;
        for(int a; n > 0; n--) {
            cin >> a;
            sum += a;
            mod[a % 4]++;
        }
        if(sum % 4 != 0) {
            cout << -1;
        } else {
            int result = min(mod[1], mod[3]);
            mod[1] -= result;
            mod[3] -= result;
            if(mod[3] > 0) {
                mod[1] = mod[3];
            }
            auto count = min(mod[2], mod[1] / 2);
            result += min(count * 2 + (mod[1] - 2 * count) / 4 * 3 + (mod[2] - count) / 2, mod[2] / 2 + mod[1] / 4 * 3 + mod[2] % 2 * 2);
            cout << result;
        }
    }
    return 0;
}
