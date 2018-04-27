#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

vector<long long> mul(vector<long long>& a, vector<long long>& b) {
    vector<long long> result(a.size() + b.size() - 1, 0);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            result[i + j] = (result[i + j] + a[i] * b[j]) % MOD;
        }
    }
    return result;
}

int main() {
    long long n, m, c;
    cin >> n >> m >> c;
    long long upper[c + 1], lower[c + 1];
    fill(upper, upper + c + 1, 0);
    fill(lower, lower + c + 1, 0);
    for(long long u; n > 0; n--) {
        cin >> u;
        upper[u]++;
    }
    for(long long l; m > 0; m--) {
        cin >> l;
        lower[l]++;
    }
    vector<long long> a;
    for(long long i = 1; i <= c; i++) {
        if(upper[i] * lower[i] > 0) {
            a.emplace_back(upper[i] * lower[i]);
        }
    }
    vector<long long> polynomial = {1};
    for(auto i : a) {
        vector<long long> b = {-i, 1};
        polynomial = mul(polynomial, b);
    }
    for(int i = polynomial.size() - 3; i >= 0; i--) {
        cout << abs(polynomial[i]) << ' ';
    }
    for(int i = 0; i < c - polynomial.size() + 2; i++) {
        cout << 0 << ' ';
    }
    return 0;
}
