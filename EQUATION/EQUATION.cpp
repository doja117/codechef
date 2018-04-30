#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, A, B, C; cin >> N >> A >> B >> C; ) {
        long long result = 0;
        for(int a = 0; a <= min(A, N); a++) {
            for(int b = 0; b <= min(B, N - a); b++) {
                result += min(C, N - a - b) + 1;
            }
        }
        cout << result << endl;
    }
    return 0;
}
