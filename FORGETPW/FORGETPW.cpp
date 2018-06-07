#include <iostream>
#include <map>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        map<char, char> map;
        for(char j, k; n > 0; n--) {
            cin >> j >> k;
            map[j] = k;
        }
        bool dot = false;
        string s;
        cin >> s;
        for(auto& i : s) {
            auto find = map.find(i);
            if(find != map.end()) {
                i = find->second;
            }
            if(i == '.') {
                dot = true;
            }
        }
        s.erase(0, s.find_first_not_of('0'));
        if(dot) {
            while(s.back() == '0') {
                s.pop_back();
            }
            if(s.back() == '.') {
                s.pop_back();
            }
        }
        if(s.empty()) {
            s = "0";
        }
        cout << s << endl;
    }
    return 0;
}
