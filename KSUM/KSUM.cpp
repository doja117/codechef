#include <iostream>
#include <set>
#include <tuple>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int A[N];
    long long sum = 0;
    for(int i = 0; cin >> A[i]; i++) {
        sum += A[i];
    }
    set<tuple<long long, int, int>, greater<tuple<long long, int, int>>> set;
    set.emplace(sum, 0, N - 1);
    do {
        auto sum = get<0>(*set.begin());
        auto begin = get<1>(*set.begin()), end = get<2>(*set.begin());
        cout << sum << ' ';
        set.erase(set.begin());
        if(begin != end) {
            set.emplace(sum - A[begin], begin + 1, end);
            set.emplace(sum - A[end], begin, end - 1);
        }
        K--;
    } while(K > 0);
    return 0;
}
