#include <iostream>
#include <vector>
using namespace std;

int F(int n) {
    int result = n % 9;
    if(result == 0) {
        return 9;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for(long long a, d, l, r; cin >> a >> d >> l >> r; ) {
        d = d % 9;
        int begin = F((a + (l - 1) % 9 * d) % 9);
        vector<int> v {begin};
        for(int next = F(v.back() + d); next != begin; next = F(v.back() + d)) {
            v.emplace_back(next);
        }
        vector<int> prefix {0};
        for(int i = 1; i < v.size(); i++) {
            prefix.emplace_back(prefix.back() + v[i - 1]);
        }
        prefix.emplace_back(prefix.back() + v.back());
        long long result = (r - l + 1) / v.size() * prefix.back() + prefix[(r - l + 1) % v.size()];
        cout << result << endl;
    }
    return 0;
}
