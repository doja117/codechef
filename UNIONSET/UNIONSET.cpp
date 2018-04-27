#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, k; cin >> n >> k; ) {
        vector<int> set[n];
        for(int i = 0; i < n; i++) {
            int size;
            cin >> size;
            for(int j = 0; j < size; j++) {
                int t;
                cin >> t;
                set[i].emplace_back(t);
            }
            sort(begin(set[i]), end(set[i]));
        }
        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                auto current = set[i].size();
                for(auto m : set[j]) {
                    if(!binary_search(begin(set[i]), end(set[i]), m)) {
                        current++;
                    }
                }
                if(current == k) {
                    result++;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
