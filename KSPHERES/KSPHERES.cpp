#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

vector<long long> multiply(vector<long long>& a, vector<long long>& b) {
    vector<long long> result(a.size() + b.size() - 1);
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
    long long upper[c + 1] = {}, lower[c + 1] = {};
    for(long long u; n > 0; n--) {
        cin >> u;
        upper[u]++;
    }
    for(long long l; m > 0; m--) {
        cin >> l;
        lower[l]++;
    }
    vector<long long> count, polynomial = {1};
    for(long long i = 1; i <= c; i++) {
        if(upper[i] * lower[i] > 0) {
            count.emplace_back(upper[i] * lower[i]);
        }
    }
    for(auto i : count) {
        vector<long long> j = {i, 1};
        polynomial = multiply(polynomial, j);
    }
    for(int i = polynomial.size() - 3; i >= 0; i--) {
        cout << polynomial[i] << ' ';
    }
    for(int i = 0; i < c - polynomial.size() + 2; i++) {
        cout << 0 << ' ';
    }
    return 0;
}
