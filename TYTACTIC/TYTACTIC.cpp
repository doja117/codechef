#include <iostream>
#include <vector>
using namespace std;

vector<int>* graph;

int lowbit(int i) {
    return i & -i;
}

int get(vector<int>& bit, int index) {
    int result = 0;
    while(index > 0) {
        result += bit[index];
        index -= lowbit(index);
    }
    return result;
}

void add(vector<int>& bit, int index, int val) {
    while(index < bit.size()) {
        bit[index] += val;
        index += lowbit(index);
    }
}

int dfs(int root, int parent, int time, int* begin, int* end) {
    begin[root] = time;
    for(auto i : graph[root]) {
        if(i != parent) {
            time = dfs(i, root, time + 1, begin, end);
        }
    }
    end[root] = time;
    return time;
}

int main() {
    int n, m;
    cin >> n >> m;
    int skill[n + 1], begin[n + 1], end[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> skill[i];
    }
    graph = new vector<int>[n + 1];
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    dfs(1, 1, 1, begin, end);
    vector<int> bit(n + 1);
    for(int i = 1; i <= n; i++) {
        add(bit, begin[i], skill[i]);
    }
    for(string m; cin >> m; ) {
        int s, x;
        switch(m[0]) {
            case 'U':
                cin >> s >> x;
                add(bit, begin[s], x - get(bit, begin[s]) + get(bit, begin[s] - 1));
                break;
            case 'Q':
                cin >> s;
                cout << get(bit, end[s]) - get(bit, begin[s] - 1) << endl;
        }
    }
    return 0;
}
