#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; ) {
        int p[n];
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        pair<int, int> interval[m];
        for(int i = 0; i < m; i++) {
            cin >> interval[i].first >> interval[i].second;
        }
        sort(interval, interval + m);
        int begin = 0;
        string result = "Possible\n";
        for(int i = 1; i < m; i++) {
            if(interval[i].first > interval[i - 1].second) {
                int start = interval[begin].first, end = interval[i - 1].second;
                for(int j = start - 1; j < end; j++) {
                    if(p[j] < start || p[j] > end) {
                        result = "Impossible\n";
                    }
                }
                begin = i;
            } else {
                interval[i].second = max(interval[i].second, interval[i - 1].second);
            }
        }
        int start = interval[begin].first, end = interval[m - 1].second;
        for(int j = start - 1; j < end; j++) {
            if(p[j] < start || p[j] > end) {
                result = "Impossible\n";
            }
        }
        cout << result;
    }
    return 0;
}
