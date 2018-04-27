#include <iostream>
#include <set>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, m; cin >> n >> m; ) {
        int dp[n], distance[n];
        fill(distance, distance + n, INT_MAX);
        vector<pair<int, int>> graph[n];
        for(int a, b, c; m > 0; m--) {
            cin >> a >> b >> c;
            a--;
            b--;
            graph[a].emplace_back(b, c);
            graph[b].emplace_back(a, c);
        }
        set<pair<int, int>> set;
        set.emplace(0, 0);
        distance[0] = 0;
        dp[0] = 1;
        do {
            auto current = set.begin()->second;
            set.erase(set.begin());
            for(auto& i : graph[current]) {
                if(distance[i.first] > distance[current] + i.second) {
                    dp[i.first] = dp[current];
                    set.erase({distance[i.first], i.first});
                    distance[i.first] = distance[current] + i.second;
                    set.emplace(distance[i.first], i.first);
                } else if (distance[i.first] == distance[current] + i.second) {
                    dp[i.first] += dp[current];
                }
            }
        } while(!set.empty());
        cout << dp[n - 1] << endl;
    }
    return 0;
}
