#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

const long long MOD = 4294967296;

int main() {
    long long q, s, a, b, result;
    cin >> q >> s >> a >> b;
    tuple<long long, int, bool> queries[q];
    for(int i = 0; i < q; i++) {
        queries[i] = {s / 2, i, s % 2};
        s = (a * s + b) % MOD;
    }
    sort(queries, queries + q);
    if(get<2>(queries[0])) {
        result = get<0>(queries[0]);
    } else {
        result = 0;
    }
    for(int i = 1; i < q; i++) {
        if(get<0>(queries[i]) == get<0>(queries[i - 1]) && get<2>(queries[i]) == get<2>(queries[i - 1])) {
            continue;
        }
        if(get<2>(queries[i])) {
            result += get<0>(queries[i]);
        } else if(get<0>(queries[i]) == get<0>(queries[i - 1])) {
            result -= get<0>(queries[i]);
        }
    }
    cout << result;
    return 0;
} 
