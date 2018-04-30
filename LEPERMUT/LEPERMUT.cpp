#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int A[N];
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        string result = "YES\n";
        for(int i = 0; i < N; i++) {
            for(int j = i + 2; j < N; j++) {
                if(A[j] < A[i]) {
                    result = "NO\n";
                }
            }
        }
        cout << result;
    }
    return 0;
}
