#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long result = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '8' || s[i] == '0') {
            result++;
        }
    }
    for(int i = 1; i < s.size(); i++) {
        if((s[i] - '0' + 10 * (s[i - 1] - '0')) % 8 == 0 && s[i - 1] != '0') {
            result++;
        }
    }
    for(int i = 2, count = 0; i < s.size(); i++) {
        if((s[i] - '0' + 10 * (s[i - 1] - '0') + 100 * (s[i - 2] - '0')) % 8 == 0) {
            result += count;
            if(s[i - 2] != '0') {
                result++;
            }
        }
        if(s[i - 2] != '0') {
            count++;
        }
    }
    cout << result;
    return 0;
}
