#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    map<int, map<int, priority_queue<tuple<int, int, int>>>> css;
    for(int i = 0; i < N; i++) {
        int id, attr, val, priority;
        cin >> id >> attr >> val >> priority;
        css[id][attr].emplace(priority, i, val);
    }
    for(int id, attr; cin >> id >> attr; ) {
        cout << get<2>(css[id][attr].top()) << endl;
    }
    return 0;
}
