#include <iostream>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string j, s; cin >> j >> s; ) {
        int result = 0;
        set<char> set;
        for(auto& c : j) {
            set.emplace(c);
        }
        for(auto& c : s) {
            if(set.find(c) != end(set)) {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
