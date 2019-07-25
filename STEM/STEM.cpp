#include <iostream>
using namespace std;

bool kmp(const string& text, const string& pattern) {
    int lps[pattern.size()];
    lps[0] = -1;
    for (int i = 1, j = -1; i < pattern.size(); i++) {
        while (j >= 0 && pattern[i - 1] != pattern[j]) {
            j = lps[j];
        }
        j++;
        if (pattern[i] == pattern[j]) {
            lps[i] = lps[j];
        } else {
            lps[i] = j;
        }
    }
    for (int i = 0, j = 0; i < text.size(); i++) {
        if (j >= 0 && text[i] != pattern[j]) {
            j = lps[j];
        }
        j++;
        if (j == pattern.size()) {
            return true;
        }
    }
    return false;
}

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
                    if(!kmp(w[i], substr)) {
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
