#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, h; cin >> n >> h; ) {
        int v[n], begin = 1, end = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            end = max(end, v[i]);
        }
        while(begin < end) {
            auto mid = (begin + end) / 2, time = 0;
            for(int i = 0; i < n; i++) {
                time += (v[i] - 1) / mid + 1;
            }
            if(time <= h) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        cout << begin << endl;
    }
    return 0;
}
