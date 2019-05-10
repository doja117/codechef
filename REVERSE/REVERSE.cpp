#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int dijkstra(vector<pair<int, int>>* graph, int n) {
    unsigned int distance[n];
    fill(distance, distance + n, -1);
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
    return distance[n - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n];
    for(int x, y; cin >> x >> y; ) {
        graph[x - 1].emplace_back(y - 1, 0);
        graph[y - 1].emplace_back(x - 1, 1);
    }
    cout << dijkstra(graph, n);
    return 0;
}
