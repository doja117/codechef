#include <iostream>
using namespace std;

int main() {
    int n, k, result = 0;
    cin >> n >> k;
    for(int t; cin >> t; ) {
        if(t % k == 0) {
            result++;
        }
    }
    cout << result;
    return 0;
}
