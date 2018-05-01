#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; cout << endl) {
        pair<int, int> prefix[N + 1];
        prefix[0] = {0, 0};
        for(int i = 1; i <= N; i++) {
            cin >> prefix[i].first;
            prefix[i] = {(prefix[i - 1].first + prefix[i].first) % N, i};
        }
        sort(prefix, prefix + N + 1);
        for(int i = 1; i <= N; i++) {
            if(prefix[i].first == prefix[i - 1].first) {
                int j = min(prefix[i].second, prefix[i - 1].second) + 1, end = max(prefix[i].second, prefix[i - 1].second);
                cout << end - j + 1 << endl;
                for(; j <= end; j++) {
                    cout << j << endl;
                }
                break;
            }
        }
    }
    return 0;
}
