#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, M; cin >> N >> M; ) {
        long long range[N + 2];
        fill(range, range + N + 2, 0);
        for(int w, x, y, z; M > 0; M--) {
            cin >> w >> x >> y >> z;
            switch(w) {
                case 1:
                    range[x] += z;
                    range[y + 1] -= z;
                    break;
                case 2:
                    range[x] -= z;
                    range[y + 1] += z;
            }
        }
        long long sum = 0, lb = LLONG_MAX, ub = LLONG_MIN;
        for(int i = 1; i <= N; i++) {
            sum += range[i];
            lb = min(lb, sum + i);
            ub = max(ub, sum + i);
        }
        cout << ub - lb << endl;
    }
    return 0;
}
