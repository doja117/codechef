#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
using namespace std;

int lowbit(int i) {
    return i & -i;
}

int get(vector<int>& bit, int index) {
    int result = 0;
    while(index > 0) {
        result += bit[index];
        index -= lowbit(index);
    }
    return result;
}

void add(vector<int>& bit, int index, int val) {
    while(index < bit.size()) {
        bit[index] += val;
        index += lowbit(index);
    }
}

int main() {
    int N;
    cin >> N;
    int A[N];
    map<int, int> map;
    for(int i = 0, j; i < N; i++) {
        cin >> j >> A[i];
        map[j] = A[i];
    }
    sort(A, A + N);
    for(auto& i : map) {
        i.second = lower_bound(A, A + N, i.second) - A + 1;
    }
    long long result = 0;
    vector<int> bit(N + 1, 0);
    for(auto it = map.rbegin(); it != map.rend(); it++) {
        add(bit, it->second, 1);
        result += get(bit, it->second - 1);
    }
    cout << result;
    return 0;
}
