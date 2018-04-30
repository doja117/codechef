#include <iostream>
using namespace std;

bool subsequence(string& m, string& w) {
    int j = 0;
    for(int i = 0; i < w.size() && j < m.size(); i++) {
        if(w[i] == m[j]) {
            j++;
        }
    }
    if(j == m.size()) {
        return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for(string m, w; cin >> m >> w; ) {
        if(subsequence(m, w) || subsequence(w, m)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
