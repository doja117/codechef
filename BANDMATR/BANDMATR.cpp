#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int nonzero = -N;
        for(int i = 0, j; i < N * N; i++) {
            cin >> j;
            if(j != 0) {
                nonzero++;
            }
        }
        int result = 0, sum = 0;
        for(int count = N - 1; sum < nonzero; count--) {
            result++;
            sum += 2 * count;
        }
        cout << result << endl;
    }
    return 0;
}
 
