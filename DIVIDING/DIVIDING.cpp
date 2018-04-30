#include <iostream>
using namespace std;

int main() {
    long long n, sum = 0;
    cin >> n;
    for(long long i; cin >> i; sum += i) {
    }
    if(sum == n * (n + 1) / 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
