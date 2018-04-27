#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, count; cin >> n; ) {
        if(n % 6 != 0) {
            cout << "Chef\n";
        } else {
            cout << "Misha\n";
        }
    }
    return 0;
}
