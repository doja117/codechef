#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int a[N];
        long long result = 0;
        for(int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a + N, greater<int>());
        for(int i = 0; i < N; i += 2) {
            result += a[i];
        }
        cout << result << endl;
    }
    return 0;
}
