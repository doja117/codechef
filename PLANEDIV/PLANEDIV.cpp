#include <iostream>
#include <map>
#include <set>
#include <tuple>
using namespace std;

int gcd(int a, int b) {
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
    for(int n; cin >> n; ) {
        set<tuple<int, int, int>> set;
        for(int a, b, c; n > 0; n--) {
            cin >> a >> b >> c;
            auto g = gcd(a, gcd(b, c));
            a /= g;
            b /= g;
            c /= g;
            if(a < 0) {
                a *= -1;
                b *= -1;
                c *= -1;
            }
            set.emplace(a, b, c);
        }
        map<pair<int, int>, int> map;
        for(auto& i : set) {
            auto g = gcd(get<0>(i), get<1>(i));
            map[{get<0>(i) / g, get<1>(i) / g}]++;
        }
        int result = 0;
        for(auto& i : map) {
            result = max(result, i.second);
        }
        cout << result << endl;
    }
    return 0;
}
