#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string s; cin >> s; ) {
        long long result = 0;
        for(long long start = 0, end = 1; end <= s.size(); end++) {
            if(s[start] != s[end]) {
                result += (end - start) * (end - start - 1) / 2;
                if(start > 0 && s[start - 1] == s[end]) {
                    result++;
                }
                start = end;
            }
        }
        cout << result << endl;
    }
    return 0;
}
