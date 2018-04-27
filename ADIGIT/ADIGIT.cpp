#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int prefix[10][n];
    for(char i = '0'; i <= '9'; i++) {
        prefix[i - '0'][0] = abs(s[0] - i);
        for(int j = 1; j < n; j++) {
            prefix[i - '0'][j] = prefix[i - '0'][j - 1] + abs(s[j] - i);
        }
    }
    for(int x; cin >> x; cout << prefix[s[x - 1] - '0'][x - 1] << endl) {
    }
    return 0;
}
