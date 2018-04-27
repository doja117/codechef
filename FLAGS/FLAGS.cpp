#include <iostream>
using namespace std;

long long solve(long long n) {
    return n * (n - 1) * (n - 1) * 2 + n * (n - 1) * (n - 2) + n * (n - 1) * (n - 2) * (n - 2) * 2;
}
 
int main() {
    int T;
    cin >> T;
    for(long long n; cin >> n; cout << solve(n) << endl) {
    }
    return 0;
}
