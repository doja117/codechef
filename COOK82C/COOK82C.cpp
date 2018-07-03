#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<long long> q1;
    queue<long long> q2;
    for(long long i; n > 0; n--) {
        cin >> i;
        q1.emplace(i);
    }
    for(int i, j = 1; cin >> i; ) {
        while(j != i) {
            if(!q1.empty()) {
                if(!q2.empty()) {
                    if(q1.top() > q2.front()) {
                        q2.emplace(q1.top() / 2);
                        q1.pop();
                    } else {
                        q2.emplace(q2.front() / 2);
                        q2.pop();
                    }
                } else {
                    q2.emplace(q1.top() / 2);
                    q1.pop();
                }
            } else {
                q2.emplace(q2.front() / 2);
                q2.pop();
            }
            j++;
        }
        long long result = LLONG_MIN;
        if(!q1.empty()) {
            result = q1.top();
        }
        if(!q2.empty() && q2.front() > result) {
            result = q2.front();
        }
        cout << result << endl;
    }
    return 0;
}
