#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, d; cin >> n >> d; ) {
        int a[n];
        long long sum = 0, result = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if(sum % n == 0) {
            for(int i = 0; i < d; i++) {
                long long current = 0, move = 0;
                for(int j = i; j < n; j += d) {
                    move += a[j] - sum / n;
                    result += abs(move);
                    current += a[j];
                }
                if(current % ((n - 1 - i) / d + 1) != 0) {
                    result = -1;
                    break;
                }
            }
        } else {
            result = -1;
        }
        cout << result << endl;
    }
    return 0;
}
