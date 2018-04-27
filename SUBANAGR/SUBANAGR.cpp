#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s, u;
    cin >> s;
    sort(s.begin(), s.end());
    for(n--; cin >> u; ) {
        string m;
        sort(u.begin(), u.end());
        set_intersection(u.begin(), u.end(), s.begin(), s.end(), back_inserter(m));
        s = m;
    }
    if(s.empty()) {
        cout << "no such string";
    } else {
        cout << s;
    }
    return 0;
}
