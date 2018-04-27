#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n];
    for(int x, y; cin >> x >> y; ) {
        x--;
        y--;
        graph[x].emplace_back(y, 0);
        graph[y].emplace_back(x, 1);
    }
    int distance[n];
    fill(distance, distance + n, INT_MAX);
    set<pair<int, int>> set;
    set.emplace(0, 0);
    distance[0] = 0;
    do {
        auto current = set.begin()->second;
        set.erase(set.begin());
        for(auto& i : graph[current]) {
            if(distance[current] + i.second < distance[i.first]) {
                set.erase({distance[i.first], i.first});
                distance[i.first] = distance[current] + i.second;
                set.emplace(distance[i.first], i.first);
            }
        }
    } while(!set.empty());
    if(distance[n - 1] == INT_MAX) {
        cout << -1;
    } else {
        cout << distance[n - 1];
    }
    return 0;
}
