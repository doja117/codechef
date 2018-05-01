#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        pair<int, int> intervals[N];
        for(int i = 0; i < N; i++) {
            cin >> intervals[i].first >> intervals[i].second;
        }
        sort(intervals, intervals + N, [](pair<int, int>& left, pair<int, int>& right){
            return left.second < right.second;
        });
        int result = 0, last = -1;
        for(int i = 0; i < N; i++) {
            if(intervals[i].first > last) {
                result++;
                last = intervals[i].second;
            }
        }
        cout << result << endl;
    }
    return 0;
} 
