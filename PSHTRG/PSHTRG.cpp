#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned int> cal(unsigned int* a, unsigned int start, unsigned int end) {
    unsigned int size = end - start, b[size];
    for(unsigned int i = start; i < end; i++) {
        b[i - start] = a[i];
    }
    sort(b, b + size);
    unsigned int index = 0;
    for(int i = size - 1; i >= 2; i--) {
        if(b[i] < b[i - 1] + b[i - 2]) {
            index = i - 2;
            break;
        }
    }
    return vector<unsigned int> (b + index, b + size);
}

unsigned int sqrt(unsigned int n) {
    unsigned int begin = 0, end = n;
    while(begin < end) {
        auto mid = (end + begin + 1) / 2;
        if(mid <= n / mid) {
            begin = mid;
        } else {
            end = mid - 1;
        }
    }
    return end;
}
 
int main() {
    unsigned int n, q;
    cin >> n >> q;
    unsigned int a[n], blocksize = sqrt(n), blocknum = (n - 1) / blocksize + 1;
    vector<unsigned int> block[blocknum];
    for(unsigned int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(unsigned int i = 0; i < blocknum; i++) {
        block[i] = cal(a, i * blocksize, min((i + 1) * blocksize, n));
    }
    for(unsigned int m, b, c; cin >> m >> b >> c; ) {
        b--;
        switch(m) {
            case 1:
                a[b] = c;
                b = b / blocksize;
                block[b] = cal(a, b * blocksize, min((b + 1) * blocksize, n));
                break;
            case 2:
                unsigned int result = 0, start = b / blocksize + 1, end = c / blocksize;
                vector<unsigned int> v;
                if(end <= start) {
                    v = cal(a, b, c);
                } else {
                    v = cal(a, b, start * blocksize);
                    for(unsigned int i = start; i < end; i++) {
                        v.insert(v.end(), block[i].begin(), block[i].end());
                    }
                    auto t = cal(a, end * blocksize, c);
                    v.insert(v.end(), t.begin(), t.end());
                }
                sort(v.begin(), v.end());
                for(unsigned int i = v.size() - 1; i >= 2; i--) {
                    if(v[i] < v[i - 1] + v[i - 2]) {
                        result = v[i] + v[i - 1] + v[i - 2];
                        break;
                    }
                }
                cout << result << endl;
        }
    }
    return 0;
}
