#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int T, k;
    cin >> T;
    for(string w; cin >> w >> k; ) {
        map<char, int> freq;
        for(auto c : w) {
            freq[c]++;
        }
        vector<int> v;
        for(auto& i : freq) {
            v.emplace_back(i.second);
        }
        sort(begin(v), end(v));
        int result = INT_MAX;
        for(int j = 1; j < w.size(); j++) {
            int current = 0, i = 0;
            while(i < v.size()) {
                if(v[i] < j) {
                    current += v[i];
                } else {
                    break;
                }
                i++;
            }
            for(int l = i + 1; l < v.size(); l++) {
                if(v[l] < j) {
                    current += v[l];
                } else if(v[l] - v[i] > k) {
                    current += v[l] - v[i] - k;
                }
            }
            result = min(result, current);
        }
        cout << result << endl;
    }
    return 0;
}
