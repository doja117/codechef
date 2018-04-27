#include <iostream>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        map<int, int> map;
        for(int i = 0, a; i < n; i++) {
            cin >> a;
            map[a]++;
        }
        int result = 0;
        for(auto& i : map) {
            result += i.second - 1;
            for(int count = i.second, next = i.first * 2; count > 1; next *= 2) {
                auto find = map.find(next);
                if(find != map.end()) {
                    count += find->first - 1;
                    result += find->first - 1;
                    find->second = 1;
                } else {
                    count--;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
