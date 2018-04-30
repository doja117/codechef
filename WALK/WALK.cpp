#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        int result = 0;
        for(int i = 0; i < n; i++) {
            int w;
            cin >> w;
            result = max(result, w + i);
        }
        cout << result << endl;
    }
    return 0;
}
