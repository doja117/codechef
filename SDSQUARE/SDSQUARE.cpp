#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long table[] = {0, 1, 4, 9};
const long long SIZE = 10000000000;
vector<long long> perfect;

long long convert(long long i) {
    long long result = 0;
    for(long long j = 1; i > 0; i /= 4, j *= 10) {
        result += table[i % 4] * j;
    }
    return result;
}

bool square(long long n) {
    long long begin = 1, end = n;
    while(begin < end) {
        auto mid = (end + begin) / 2 + 1;
        if(mid * mid <= n) {
            begin = mid;
        } else {
            end = mid - 1;
        }
    }
    if(begin * begin == n) {
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for(long long i = 1; true; i++) {
        long long j = convert(i);
        if(j > SIZE) {
            break;
        }
        if(square(j)) {
            perfect.emplace_back(j);
        }
    }
    for(long long a, b; cin >> a >> b; ) {
        cout << lower_bound(perfect.begin(), perfect.end(), b + 1) - lower_bound(perfect.begin(), perfect.end(), a) << endl;
    }
    return 0;
}
