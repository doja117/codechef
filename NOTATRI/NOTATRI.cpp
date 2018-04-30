#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    for(int N; cin >> N; ) {
        if(N == 0) {
            break;
        }
        int L[N], result = 0;
        for(int i = 0; i < N; i++) {
            cin >> L[i];
        }
        sort(L, L + N);
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j + 1 < N; j++) {
                int begin = j + 1, end = N - 1;
                while(begin < end) {
                    auto mid = (begin + end) / 2;
                    if(L[i] + L[j] < L[mid]) {
                        end = mid;
                    } else {
                        begin = mid + 1;
                    }
                }
                if(L[i] + L[j] < L[begin]) {
                    result += N - begin;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
