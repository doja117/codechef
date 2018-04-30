#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int s[N], result = INT_MAX;
        for(int i = 0; i < N; i++) {
            cin >> s[i];
        }
        sort(s, s + N);
        for(int i = 1; i < N; i++) {
            result = min(result, s[i] - s[i - 1]);
        }
        cout << result << endl;
    }
    return 0;
}
