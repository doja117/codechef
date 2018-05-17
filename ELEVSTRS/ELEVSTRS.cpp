#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(long long n, v1, v2; cin >> n >> v1 >> v2; ) {
        if(2 * n * n * v2 * v2 < 4 * n * n * v1 * v1) {
            cout << "Stairs\n";
        } else {
            cout << "Elevator\n";
        }
    }
    return 0;
}
