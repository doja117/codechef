#include <iostream>
#include <algorithm>
using namespace std;

int dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int n, result = 0;
    cin >> n;
    for(int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; ) {
        int d[] = {dist(x1, y1, x2, y2), dist(x2, y2, x3, y3), dist(x1, y1, x3, y3)};
        sort(begin(d), end(d));
        if(d[2] == d[1] + d[0]) {
            result++;
        }
    }
    cout << result;
    return 0;
}
