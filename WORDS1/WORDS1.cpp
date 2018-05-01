#include <iostream>
#include <map>
#include <set>
#include <stack>
using namespace std;

bool check(int n) {
    map<char, int> in, out;
    map<char, set<char>> graph;
    map<char, bool> visited;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        out[s.front()]++;
        in[s.back()]++;
        graph[s.front()].emplace(s.back());
        graph[s.back()].emplace(s.front());
        visited[s.front()] = false;
        visited[s.back()] = false;
    }
    stack<char> stack;
    stack.emplace(visited.begin()->first);
    visited.begin()->second = true;
    do {
        auto top = stack.top();
        stack.pop();
        for(auto& i : graph[top]) {
            auto find = visited.find(i);
            if(!find->second) {
                find->second = true;
                stack.emplace(i);
            }
        }
    } while(!stack.empty());
    for(auto& i : visited) {
        if(i.second == false) {
            return false;
        }
    }
    int tail = 0, head = 0;
    for(auto& i : visited) {
        auto t = in[i.first], u = out[i.first];
        if(t - u == 1) {
            tail++;
        } else if(u - t == 1) {
            head++;
        } else if(t != u) {
            return false;
        }
    }
    if((head + tail == 0) || (head == 1 && tail == 1)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int t;
    cin >> t;
    for(int n; t > 0; t--) {
        cin >> n;
        if(check(n)) {
            cout << "Ordering is possible.\n";
        } else {
            cout << "The door cannot be opened.\n";
        }
    }
    return 0;
}
