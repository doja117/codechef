#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, k; cin >> n >> k; ) {
        pair<int, int> oranges[n];
        for(int i = 0; i < n; i++) {
            cin >> oranges[i].first >> oranges[i].second;
        }
        int result = 0;
        for(int i = 0; i < (1 << n); i++) {
            int cost = 0, weight = 0;
            for(int j = i, k = 0; j > 0; j /= 2, k++) {
                if(j % 2 == 1) {
                    cost += oranges[k].first;
                    weight += oranges[k].second;
                }
            }
            if(cost <= k) {
                result = max(result, weight);
            }
        }
        cout << result << endl;
    }
    return 0;
}
