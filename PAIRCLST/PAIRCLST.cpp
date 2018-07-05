#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int dist[n], closest[n], result = INT_MAX;
    vector<pair<int, int>> graph[n];
    fill(dist, dist + n, INT_MAX);
    set<pair<int, int>> set;
    for(int i; k > 0; k--) {
        cin >> i;
        set.emplace(0, i - 1);
        dist[i - 1] = 0;
        closest[i - 1] = i - 1;
    }
    for(int x, y, z; cin >> x >> y >> z; ) {
        graph[x - 1].emplace_back(y - 1, z);
        graph[y - 1].emplace_back(x - 1, z);
    }
    do {
        auto current = set.begin()->second;
        set.erase(set.begin());
        for(auto& i : graph[current]) {
            if(dist[current] < dist[i.first] - i.second) {
                set.erase({dist[i.first], i.first});
                dist[i.first] = dist[current] + i.second;
                closest[i.first] = closest[current];
                set.emplace(dist[i.first], i.first);
            }
        }
    } while(!set.empty());
    for(int i = 0; i < n; i++) {
        for(auto& j : graph[i]) {
            if(closest[i] != closest[j.first]) {
                result = min(result, dist[i] + dist[j.first] + j.second);
            }
        }
    }
    cout << result;
    return 0;
}
