#include <iostream>
using namespace std;

long long count(long long n, long long d) {
    auto s = to_string(n);
    for(auto i = 0; i < s.size(); i++) {
        if(s[i] == d + '0') {
            if(d == 0) {
                s[i] = '9';
                s[i - 1]--;
            } else {
                s[i]--;
            }
            if(d == 9) {
                for(int j = i + 1; j < s.size(); j++) {
                    s[j] = '8';
                }
            } else {
                for(int j = i + 1; j < s.size(); j++) {
                    s[j] = '9';
                }
            }
            break;
        }
    }
    if(d == 0) {
        for(long long i = s.size() - 1, t = 1; i >= 0; i--, t *= 9) {
            n -= (s[i] - '0') * t;
        }
    } else {
        for(long long i = s.size() - 1, t = 1; i >= 0; i--, t *= 9) {
            if(s[i] - '0' > d) {
                n -= (s[i] - '0' - 1) * t;
            } else {
                n -= (s[i] - '0') * t;
            }
        }
    }
    return n;
}

long long gcd(long long a, long long b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    for(long long N; cin >> N; ) {
        long long top = 0, bottom = 10 * N;
        for(long long d = 0; d <= 9; d++) {
            top += count(N, d);
        }
        auto g = gcd(top, bottom);
        top /= g;
        bottom /= g;
        cout << top << '/' << bottom << endl;
    }
    return 0;
}
