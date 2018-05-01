#include <iostream>
#include <deque>
#include <climits>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m;
    int A[n][m], rowsum[n][m + 1], sum[n + 1][m + 1];
    for(int i = 0; i < n; i++) {
        rowsum[i][0] = 0;
        for(int j = 0; j < m; j++) {
            cin >> A[i][j];
            rowsum[i][j + 1] = rowsum[i][j] + A[i][j];
        }
    }
    for(int i = 0; i <= m; i++) {
        sum[0][i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        sum[i][0] = 0;
        for(int j = 1; j <= m; j++) {
            sum[i][j] = rowsum[i - 1][j] + sum[i - 1][j];
        }
    }
    cin >> q;
    for(int a, b; cin >> a >> b; ) {
        int rowmax[n][m - b + 1], result = INT_MAX;
        for(int i = 0; i < n; i++) {
            deque<int> list;
            for(int j = 0; j < b; j++) {
                while(!list.empty() && A[i][j] >= A[i][list.back()]) {
                    list.pop_back();
                }
                list.emplace_back(j);
            }
            for(int j = b; j < m; j++) {
                rowmax[i][j - b] = A[i][list.front()];
                if(!list.empty() && list.front() <= j - b) {
                    list.pop_front();
                }
                while(!list.empty() && A[i][j] >= A[i][list.back()]) {
                    list.pop_back();
                }
                list.emplace_back(j);
            }
            rowmax[i][m - b] = A[i][list.front()];
        }
        for(int i = 0; i <= m - b; i++) {
            deque<int> list;
            for(int j = 0; j < a; j++) {
                while(!list.empty() && rowmax[j][i] >= rowmax[list.back()][i]) {
                    list.pop_back();
                }
                list.emplace_back(j);
            }
            for(int j = a; j < n; j++) {
                result = min(result, a * b * rowmax[list.front()][i] - sum[j][i + b] - sum[j - a][i] + sum[j][i] + sum[j - a][i + b]);
                if(!list.empty() && list.front() <= j - a) {
                    list.pop_front();
                }
                while(!list.empty() && rowmax[j][i] >= rowmax[list.back()][i]) {
                    list.pop_back();
                }
                list.emplace_back(j);
            }
            result = min(result, a * b * rowmax[list.front()][i] - sum[n][i + b] - sum[n - a][i] + sum[n][i] + sum[n - a][i + b]);
        }
        cout << result << endl;
    }
    return 0;
}
