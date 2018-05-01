#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; cout << endl) {
        int sum = 0, count = N;
        for(int i = 0, B; i < N; i++) {
            cin >> B;
            if(B == 0) {
                count--;
            } else {
                sum += B;
            }
        }
        if(sum >= 100 && sum < 100 + count) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
    return 0;
} 
