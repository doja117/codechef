#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, open = 0;
    cin >> N >> K;
    vector<bool> tweet(N + 1);
    for(string s; cin >> s; cout << open << endl) {
        if(s.size() == 5) {
            int i;
            cin >> i;
            if(tweet[i]) {
                open--;
            } else {
                open++;
            }
            tweet[i] = !tweet[i];
        } else {
            fill(begin(tweet), end(tweet), 0);
            open = 0;
        }
    }
    return 0;
}
