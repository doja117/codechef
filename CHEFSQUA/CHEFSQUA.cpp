#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, result;
    cin >> n;
    if(n == 0) {
        result = 4;
    } else {
        result = 3;
    }
    pair<int, int> point[n];
    for(int i = 0; cin >> point[i].first >> point[i].second; i++) {
    }
    set<pair<int, int>> set(point, point + n);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int x1 = point[i].first, y1 = point[i].second;
            int x2 = point[j].first, y2 = point[j].second;
            pair<int, int> p1{x1 + y2 - y1, y1 + x1 - x2}, p2{x2 + y2 - y1, y2 + x1 - x2};
            pair<int, int> p3{x1 + y1 - y2, y1 + x2 - x1}, p4{x2 + y1 - y2, y2 + x2 - x1};
            result = min(result, (int)(2 - set.count(p1) - set.count(p2)));
            result = min(result, (int)(2 - set.count(p3) - set.count(p4)));
        }
    }
    cout << result;
    return 0;
}
