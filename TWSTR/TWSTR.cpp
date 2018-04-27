#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    pair<string, int> recipe[n];
    for(int i = 0; i < n; i++) {
        cin >> recipe[i].first >> recipe[i].second;
    }
    cin >> q;
    for(string s; cin >> s; ) {
        string result = "NO";
        int priority = INT_MIN;
        for(int i = 0; i < n; i++) {
            bool match = true;
            for(int j = 0; j < s.size(); j++) {
                if(s[j] != recipe[i].first[j]) {
                    match = false;
                    break;
                }
            }
            if(match && recipe[i].second > priority) {
                priority = recipe[i].second;
                result = recipe[i].first;
            }
        }
        cout << result << endl;
    }
    return 0;
}
