#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int result = 0;
        while(n != 0) {
            result += n % 10;
            n /= 10;
        }
        cout << result << endl;
    }
    return 0;
}
