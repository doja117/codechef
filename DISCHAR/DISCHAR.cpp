#include <iostream>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        cout << set<char> (begin(s), end(s)).size() << endl;
    }
    return 0;
}
