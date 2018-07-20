#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long sum;

long long gcd(long long a, long long b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long dfs(long long root, long long parent, vector<pair<long long, long long>>* graph, set<long long>& a) {
    long long result;
    if(a.find(root) != a.end()) {
        result = 1;
    } else {
        result = 0;
    }
    for(auto& i : graph[root]) {
        if(i.first != parent) {
            auto t = dfs(i.first, root, graph, a);
            sum += 2 * t * i.second * (a.size() - t);
            result += t;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for(long long n, m; cin >> n >> m; ) {
        sum = 0;
        vector<pair<long long, long long>> graph[n];
        set<long long> a;
        for(long long i = 1, v, u ,l; i < n; i++) {
            cin >> v >> u >> l;
            graph[u - 1].emplace_back(v - 1, l);
            graph[v - 1].emplace_back(u - 1, l);
        }
        for(long long i = 0, j; i < m; i++) {
            cin >> j;
            a.emplace(j - 1);
        }
        dfs(0, -1, graph, a);
        long long bot = m * m, g = gcd(sum, bot);
        cout << sum / g << ' ' << bot / g << endl;
    }
    return 0;
}
