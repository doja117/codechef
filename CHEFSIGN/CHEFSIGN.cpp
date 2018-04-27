#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string s; cin >> s; ) {
        int less = 0, greater = 0, max_less = 0, max_greater = 0;
        for(auto i : s) {
            if(i == '<') {
                greater = 0;
                less++;
                if(less > max_less) {
                    max_less = less;
                }
            } else if(i == '>') {
                less = 0;
                greater++;
                if(greater > max_greater) {
                    max_greater = greater;
                }
            }
        }
        cout << max(max_less, max_greater) + 1 << endl;
    }
    return 0;
}
