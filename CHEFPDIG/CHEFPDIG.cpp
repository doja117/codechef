#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string s; cin >> s; ) {
        map<char, int> map;
        for(auto c : s) {
            map[c]++;
        }
        string result;
        for(auto& i : map) {
            if(i.second > 1) {
                char c = i.first - '0' + 10 * (i.first - '0');
                if(c >= 'A' && c <= 'Z') {
                    result.push_back(c);
                }
            }
            for(auto& j : map) {
                if(i != j) {
                    char c = i.first - '0' + 10 * (j.first - '0');
                   if(c >= 'A' && c <= 'Z') {
                        result.push_back(c);
                    }
                 }
            }
        }
        sort(begin(result), end(result));
        result.push_back('\n');
        cout << result;
    }
    return 0;
}
