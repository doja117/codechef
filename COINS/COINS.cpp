#include <iostream>
#include <map>
using namespace std;

map<long long, long long> dp;

long long count(long long N) {
    if(N == 0) {
        return 0;
    }
    auto find = dp.find(N);
    if(find != dp.end()) {
    	return find->second;
    }
    auto result = max(N, count(N / 2) + count(N / 3) + count(N / 4));
    dp[N] = result;
    return result;
}

int main() {
    for(long long N; cin >> N; ) {
        cout << count(N) << endl;
    }
    return 0;
}
