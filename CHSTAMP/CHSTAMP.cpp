#include <map>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int SIZE = 50001;

int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; ) {
        int stamp[n];
        for(int i = 0; i < n; i++) {
            cin >> stamp[i];
        }
        vector<pair<int,int>> edge[SIZE];
        for(int t, a, b; m > 0; m--) {
			cin >> t >> a >> b;
			edge[t].emplace_back(a, b);
        }
        int max_type[SIZE];
        for(int i = 0; i < SIZE; i++) {
            max_type[i] = i;
        }
        for(int i = SIZE - 1; i >= 0; i--) {
            map<int, vector<int>> graph;
            for(auto it = edge[i].begin(); it != edge[i].end(); it++) {
                graph[it->first].emplace_back(it->second);
                graph[it->second].emplace_back(it->first);
            }
            map<int, int> map;
            int component_num = 0;
            for(auto& i : graph) {
                if(map.find(i.first) == map.end()) {
                    map[i.first] = component_num;
                    queue<int> queue;
                    queue.emplace(i.first);
                    vector<int> v;
                    do {
                        v.push_back(queue.front());
                        for(auto& j : graph[queue.front()]) {
                            if(map.find(j) == map.end()) {
                                map[j] = component_num;
                                queue.emplace(j);
                            }
                        }
                        queue.pop();
                    } while(!queue.empty());
                    int value = 0;
                    for(auto& j : v) {
                        value = max(value, max_type[j]);
                    }
                    for(auto& j : v) {
                        max_type[j] = value;
                    }
                    component_num++;
                }
            }
        }
        long long result = 0;
        for(int i = 0; i < n; i++) {
            result += max_type[stamp[i]];
        }
        cout << result << endl;
    }
    return 0;
}
