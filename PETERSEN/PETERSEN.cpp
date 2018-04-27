#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> graph[10];
    for(int i : {0, 1, 2, 3, 4}) {
        graph[i].emplace_back((i + 4) % 5);
        graph[i].emplace_back((i + 1) % 5);
        graph[i].emplace_back(i + 5);
    }
    for(int i : {5, 6, 7, 8, 9}) {
        graph[i].emplace_back(5 + (i + 2) % 5);
        graph[i].emplace_back(5 + (i + 3) % 5);
        graph[i].emplace_back(i - 5);
    }
    for(string s; cin >> s; ) {
        string result;
        result.push_back(s[0] - 'A' + '0');
        for(int i = 1; i < s.size(); i++) {
            for(auto j : graph[result.back() - '0']) {
                if((j % 5) + 'A' == s[i]) {
                    result.push_back(j + '0');
                    break;
                }
            }
            if(result.size() != i + 1) {
                break;
            }
        }
        if(result.size() != s.size()) {
            result.clear();
            result.push_back(s[0] - 'A' + 5 + '0');
            for(int i = 1; i < s.size(); i++) {
                for(auto j : graph[result.back() - '0']) {
                    if((j % 5) + 'A' == s[i]) {
                        result.push_back(j + '0');
                        break;
                    }
                }
                if(result.size() != i + 1) {
                    break;
                }
            }
        }
        if(result.size() != s.size()) {
            result = "-1";
        }
        result.push_back('\n');
        cout << result;
    }
    return 0;
}
