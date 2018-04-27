#include <iostream>
#include <map>
using namespace std;

int main() {
    int N, Q;
    map<string, string> map;
    for(cin >> N >> Q; N > 0; N--) {
        string s, t;
        cin >> s >> t;
        map[s] = t;
    }
    for(string s; cin >> s; ) {
        auto find = s.rfind('.');
        string result = "unknown\n";
        if(find != string::npos) {
            auto it = map.find(s.substr(find + 1));
            if(it != end(map)) {
                result = it->second;
                result.push_back('\n');
            }
        }
        cout << result;
    }
    return 0;
}
