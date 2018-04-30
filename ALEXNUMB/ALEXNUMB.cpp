#include <iostream>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        long long result = 0, single = 0;
        map<int, int> map;
        for(int a; n > 0; n--) {
            cin >> a;
            map[a]++;
        }
        for(auto& i : map) {
            if(i.second == 1) {
                single++;
            } else {
                result += i.second * (i.second - 1) / 2;
            }
        }
        result += single * (single - 1) / 2;
        cout << result << endl;
    }
    return 0;
}
