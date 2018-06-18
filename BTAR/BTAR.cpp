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
            result += mod[2] / 2 + max(mod[1], mod[3]) / 4 * 3 + mod[2] % 2 * 2;
            cout << result;
        }
    }
    return 0;
} 
