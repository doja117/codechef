#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string s; cin >> s; ) {
        map<char, int> count;
        int max = 0;
        char c;
        for(auto i : s) {
            auto current = ++count[i];
            if(current > max) {
                max = current;
                c = i;
            }
        }
        string result;
        if(s.size() % 2 == 1 && max == s.size() / 2 + 1) {
            for(int i = 0; i < s.size(); i++) {
                if(s[i] != c) {
                    result.push_back(c);
                    result.push_back(s[i]);
                }
            }
            result.push_back(c);
        } else {
        sort(begin(s), end(s));
            for(int i = 0; i < s.size() / 2; i++) {
                result.push_back(s[i + s.size() / 2]);
                result.push_back(s[i]);
            }
            if(s.size() != result.size()) {
                result.push_back(s.back());
            }
        }
        for(int i = 1; i < s.size(); i++) {
            if(result[i] == result[i - 1]) {
                result = "-1";
                break;
            }
        }
        result.push_back('\n');
        cout << result;
    }
    return 0;
}
