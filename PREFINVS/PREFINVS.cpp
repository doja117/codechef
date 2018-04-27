#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    char current = '1';
    int result = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == current) {
            result++;
            current = 1 - current + '0' + '0';
        }
    }
    cout << result;
    return 0;
}
