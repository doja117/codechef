#include <iostream>
using namespace std;

int factorial[] {1, 1, 2, 6, 24, 120, 720};

int C(int n, int k) {
    return factorial[n] / factorial[k] / factorial[n - k];
}

int main() {
    int x, n, result = 0;
    cin >> x >> n;
    for(string s; cin >> s; ) {
        for(int i = 0; i < 9; i++) {
            int free = 0;
            free += 1 - (s[4 * i] - '0');
            free += 1 - (s[4 * i + 1] - '0');
            free += 1 - (s[4 * i + 2] - '0');
            free += 1 - (s[4 * i + 3] - '0');
            free += 1 - (s[53 - 2 * i] - '0');
            free += 1 - (s[53 - 2 * i - 1] - '0');
            if(free >= x) {
                result += C(free, x);
            }
        }
    }
    cout << result;
	return 0;
}
