#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N, min = INT_MAX, max = 0;
    pair<int, int> result;
    cin >> N;
    for(int x1, y1, x2, y2, x3, y3, i = 1; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; i++) {
        int t = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
        if(t >= max) {
            max = t;
            result.second = i;
        }
        if(t <= min) {
            min = t;
            result.first = i;
        }
    }
    cout << result.first << ' ' << result.second;
    return 0;
}
