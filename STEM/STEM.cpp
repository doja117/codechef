#include <iostream>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        string w[N], result = "";
        for(int i = 0; i < N; i++) {
            cin >> w[i];
        }
        for(int i = 0; i < w[0].size(); i++) {
            for(int j = 1; i + j <= w[0].size(); j++) {
                auto substr = w[0].substr(i, j);
                bool stem = true;
                for(int i = 1; i < N; i++) {
                    if(w[i].find(substr) == string::npos) {
                        stem = false;
                        break;
                    }
                }
                if(stem) {
                    if(substr.size() > result.size() || (substr.size() == result.size() && substr < result)) {
                        result = substr;
                    }
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
