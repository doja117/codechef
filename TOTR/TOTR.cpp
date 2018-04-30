#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    string permutation;
    cin >> permutation;
    for(string s; cin >> s; cout << endl) {
        for(auto c : s) {
            switch(c) {
                case '_':
                    cout << ' ';
                    break;
                default:
                    if(isupper(c)) {
                        cout << (char)toupper(permutation[tolower(c) - 'a']);
                    } else if(isalpha(c)) {
                        cout << permutation[c - 'a'];
                    } else {
                        cout << c;
                    }
            }
        }
    }
    return 0;
}
