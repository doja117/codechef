#include <iostream>
using namespace std;

int main() {
    long long a;
    cin >> a;
    a = a % 6;
    if(a == 1 || a == 0 || a == 3) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}
