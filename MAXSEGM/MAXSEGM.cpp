#include <iostream>
#include <map>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        long long sum[n + 1];
        int c[n + 1];
        for(int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        sum[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> sum[i];
            sum[i] += sum[i - 1];
        }
        long long result = 0;
        map<int, int> map;
        bool unique = true;
        for(int begin = 1, end = 1; end <= n; begin++) {
            while(end <= n && unique) {
                auto t = ++map[c[end]];
                if(t == 2) {
                    unique = false;
                } else {
                    result = max(result, sum[end] - sum[begin - 1]);
                }
                end++;
            }
            auto t = --map[c[begin]];
            if(t == 1) {
                unique = true;
                result = max(result, sum[end - 1] - sum[begin]);
            }
        }
        cout << result << endl;
    }
    return 0;
}
