#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int m = a.size(), n = m + b.size() + 1, inverse[n], temp[n], sa[n];
    a.push_back('0');
    a.append(b);
    temp[0] = 0;
    temp[n - 1] = n;
    for(int i = 0; i < n; i++) {
        sa[i] = i;
        inverse[i] = a[i];
    }
    for(int gap = 1; temp[n - 1] != n - 1; gap *= 2) {
        auto cmp = [&gap, &inverse, &n](int i, int j) {
            if(inverse[i] != inverse[j]) {
                return inverse[i] < inverse[j];
            }
            if(i + gap < n && j + gap < n) {
                return inverse[i + gap] < inverse[j + gap];
            }
            return i > j;
        };
        sort(sa, sa + n, cmp);
        for(int i = 0; i < n - 1; i++) {
            temp[i + 1] = temp[i] + cmp(sa[i], sa[i + 1]);
        }
        for(int i = 0; i < n; i++) {
            inverse[sa[i]] = temp[i];
        }
    }
    int* lcp = temp, result = 0, index = n, candidate = n;
    for(int i = 0, k = 0; i < n; i++) {
        if(inverse[i] == n - 1) {
            k = 0;
            continue;
        }
        for(int j = sa[inverse[i] + 1]; a[i + k] == a[j + k]; k++) {
        }
        lcp[inverse[i]] = k;
        if(k > 0) {
            k--;
        }
    }
    for(int i = 1; i < n; i++) {
        if(sa[i] < m && sa[i - 1] > m || sa[i] > m && sa[i - 1] < m) {
            result = max(result, lcp[i - 1]);
        }
    }
    for(int i = 1; i < n; i++) {
        if(lcp[i - 1] >= result) {
            if(sa[i] < m && sa[i - 1] > m || sa[i] > m && sa[i - 1] < m) {
                index = min(index, max(sa[i], sa[i - 1]));
                while(i + 1 < n && lcp[i] >= result) {
                    i++;
                    if(sa[i] > m) {
                        index = min(index, sa[i]);
                    }
                }
                index = min(index, candidate);
            } else if(min(sa[i], sa[i - 1]) > m) {
                candidate = min(candidate, min(sa[i], sa[i - 1]));
            }
        } else {
            candidate = n;
        }
    }
    cout << a.substr(index, result) << endl << result;
    return 0;
}
