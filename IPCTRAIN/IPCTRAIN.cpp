#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, d; cin >> n >> d; ) {
        vector<pair<int, int>> day[d + 1];
        priority_queue<pair<int, int>> queue;
        while(n > 0) {
            int d, t, s;
            cin >> d >> t >> s;
            day[d].emplace_back(s, t);
            n--;
        }
        for(int i = 1; i <= d; i++) {
            for(auto& j : day[i]) {
                queue.emplace(j);
            }
            if(!queue.empty()) {
                auto top = queue.top();
                queue.pop();
                if(top.second != 1) {
                    queue.emplace(top.first, top.second - 1);
                }
            }
        }
        long long result = 0;
        while(!queue.empty()) {
            result += (long long)queue.top().first * queue.top().second;
            queue.pop();
        }
        cout << result << endl;
    }
    return 0;
}
