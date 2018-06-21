#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int T;
    cin >> T;
    for(int n, k; cin >> n >> k; ) {
        int* set[n], size[n];
        for(int i = 0; i < n; i++) {
            cin >> size[i];
            set[i] = new int[size[i]];
            for(int j = 0; j < size[i]; j++) {
                cin >> set[i][j];
            }
            sort(set[i], set[i] + size[i]);
        }
        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                auto current = size[i];
                for(int m = 0; m < size[j]; m++) {
                    if(!binary_search(set[i], set[i] + size[i], set[j][m])) {
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
