#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; cout << endl) {
        vector<bool> job(n, true);
        for(int i; m > 0; m--) {
            cin >> i;
            job[i - 1] = false;
        }
        vector<int> result[2];
        for(int i = 0, j = 0; i < n; i++) {
            if(job[i]) {
                result[j % 2].emplace_back(i + 1);
                j++;
            }
        }
        for(auto i : result[0]) {
            cout << i << ' ';
        }
        cout << endl;
        for(auto i : result[1]) {
            cout << i << ' ';
        }
    }
    return 0;
}
