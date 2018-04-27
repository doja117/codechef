#include <iostream>
using namespace std;

long long pow(long long x, long long n) {
    long long result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % 9;
        }
        n /= 2;
        x = x * x % 9;
    }
    if(result == 0) {
        return 9;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for(long long a, n; cin >> a >> n; cout << pow(a % 9, n) << endl) {
    }
    return 0;
}
