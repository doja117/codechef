#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        string s;
        cin >> s;
        auto result = s;
        for(int i = 0; i < N; i++) {
            auto t = s;
            t.erase(i, 1);
            for(int j = 0; j < N; j++) {
                auto u = t;
                u.insert(j, 1, s[i]);
                result = min(result, u);
            }
        }
        result.push_back('\n');
        cout << result;
    }
    return 0;
}
