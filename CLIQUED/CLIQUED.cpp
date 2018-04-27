#include <iostream>
#include <set>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, K, X, M, S; cin >> N >> K >> X >> M >> S; cout << endl) {
        vector<pair<int, int>> graph[N];
        for(int a, b, c; M > 0; M--) {
            cin >> a >> b >> c;
            graph[a - 1].emplace_back(b - 1, c);
            graph[b - 1].emplace_back(a - 1, c);
        }
        long long dist[N];
        fill(dist, dist + N, LLONG_MAX);
        set<pair<long long, int>> set;
        set.emplace(0, S - 1);
        dist[S - 1] = 0;
        do {
            auto current = set.begin()->second;
            set.erase(set.begin());
            for(auto& i : graph[current]) {
                if(dist[current] < dist[i.first] - i.second) {
                    set.erase({dist[i.first], i.first});
                    dist[i.first] = dist[current] + i.second;
                    set.emplace(dist[i.first], i.first);
                }
            }
            if(current < K) {
                for(int i = 0; i < K; i++) {
                    if(dist[current] < dist[i] - X) {
                        set.erase({dist[i], i});
                        dist[i] = dist[current] + X;
                        set.emplace(dist[i], i);
                    }
                }
                break;
            }
        } while(!set.empty());
        while(!set.empty()) {
            auto current = set.begin()->second;
            set.erase(set.begin());
            for(auto& i : graph[current]) {
                if(dist[current] < dist[i.first] - i.second) {
                    set.erase({dist[i.first], i.first});
                    dist[i.first] = dist[current] + i.second;
                    set.emplace(dist[i.first], i.first);
                }
            }
        }
        for(int i = 0; i < N; i++) {
            cout << dist[i] << ' ';
        }
    }
    return 0;
} 
