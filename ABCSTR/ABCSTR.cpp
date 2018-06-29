#include <iostream>
#include <map>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<pair<long long, long long>, long long> map;
    map[{0, 0}]++;
    long long result = 0, ab = 0, bc = 0;
    for(auto i : s) {
        switch(i) {
            case 'A':
                ab++;
                break;
            case 'B':
                ab--;
                bc--;
                break;
            case 'C':
                bc++;
        }
        auto j = map.find({ab, bc});
        if(j != map.end()) {
            result += j->second;
            j->second++;
        } else {
            map[{ab, bc}]++;
        }
    }
    cout << result;
    return 0;
}
