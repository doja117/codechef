#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> graph[s.size()];
    for(int i = 1; i < s.size(); i++) {
        graph[i].emplace_back(i - 1);
        graph[i - 1].emplace_back(i);
    }
    vector<bool> visited(s.size()), flag(10);
    visited[0] = true;
    queue<int> queue;
    queue.emplace(0);
    int result = 0;
    do {
        for(auto size = queue.size(); size > 0; size--) {
            auto front = queue.front();
            if(front == s.size() - 1) {
                cout << result;
                return 0;
            }
            queue.pop();
            for(auto i : graph[front]) {
                if(!visited[i] && !flag[s[i] - '0']) {
                    visited[i] = true;
                    queue.emplace(i);
                }
            }
            if(!flag[s[front] - '0']) {
                flag[s[front] - '0'] = true;
                for(int i = 0; i < s.size(); i++) {
                    if(s[i] == s[front] && !visited[i]) {
                        visited[i] = true;
                        queue.emplace(i);
                    }
                }
            }
        }
        result++;
    } while(!queue.empty());
    return 0;
}
