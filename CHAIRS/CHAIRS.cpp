#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        string s;
        cin >> s;
        vector<int> v;
        for(auto i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                v.emplace_back(i);
            }
        }
        int result = N;
        for(int i = 1; i < v.size(); i++) {
            auto t = N - v.size() - v[i] + v[i - 1] + 1;
            if(t < result) {
                result = t;
            }
        }
        auto t = v.back() - v.front() - v.size() + 1;
        if(t < result) {
            result = t;
        }
        cout << result << endl;
    }
    return 0;
}
