#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        long long count2 = 0, count = 0;
        for(int j; n > 0; n--) {
            cin >> j;
            if(j == 2) {
                count2++;
            } else if(j > 2) {
                count++;
            }
        }
        cout << count2 * count + count * (count - 1) / 2 << endl;
    }
    return 0;
}
