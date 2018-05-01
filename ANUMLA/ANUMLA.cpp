#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; cout << endl) {
        multiset<int> sum;
        vector<int> result;
        for(int i = 0; i < (1 << N); i++) {
            int v;
            cin >> v;
            sum.emplace(v);
        }
        sum.erase(0);
        for(auto i : sum) {
            for(int j = 1; j < (1 << result.size()); j++) {
                int current = i;
                for(int k = j, l = 0; k > 0; k /= 2, l++) {
                    if(k % 2 == 1) {
                        current += result[l];
                    }
                }
                sum.erase(current);
            }
            result.emplace_back(i);
        }
        for(int i : result) {
            cout << i << ' ';
        }
    }
    return 0;
}
