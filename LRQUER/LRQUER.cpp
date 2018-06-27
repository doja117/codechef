#include <iostream>
#include <map>
using namespace std;

long long sqrt(long long n) {
    long long begin = 0, end = n;
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
    int T;
    cin >> T;
    for(long long n, q; cin >> n >> q; ) {
        long long a[n], blocksize = sqrt(n), blocknum = (n - 1) / blocksize + 1;
        map<long long, long long> block[blocknum];
        for(long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(long long i = 0; i < blocknum; i++) {
            for(long long j = i * blocksize; j < min(n, (i + 1) * blocksize); j++) {
                block[i][2 * a[j]]++;
            }
        }
        for(long long t, l, r; q > 0; q--) {
            cin >> t >> l >> r;
            long long start = (l - 1) / blocksize + 1, end = (r - 1) / blocksize, result = 0;
            switch(t) {
                case 1:
                    if(end <= start) {
                        for(long long i = l; i < r; i++) {
                            result = max(result, (a[i] - a[l - 1]) * (a[r - 1] - a[i]));
                        }
                    } else {
                        for(long long i = l; i < start * blocksize; i++) {
                            result = max(result, (a[i] - a[l - 1]) * (a[r - 1] - a[i]));
                        }
                        for(long long i = start; i < end; i++) {
                            auto it = block[i].lower_bound(a[l - 1] + a[r - 1]);
                            if(it != block[i].end()) {
                                result = max(result, (it->first / 2 - a[l - 1]) * (a[r - 1] - it->first / 2));
                            }
                            if(it != block[i].begin()) {
                                it = prev(it);
                                result = max(result, (it->first / 2 - a[l - 1]) * (a[r - 1] - it->first / 2));
                            }
                        }
                        for(long long i = end * blocksize; i < r; i++) {
                            result = max(result, (a[i] - a[l - 1]) * (a[r - 1] - a[i]));
                        }
                    }
                    cout << result << endl;
                    break;
                case 2:
                    auto it = block[(l - 1) / blocksize].find(2 * a[l - 1]);
                    if(it->second != 1) {
                        it->second--;
                    } else {
                        block[(l - 1) / blocksize].erase(it);
                    }
                    a[l - 1] = r;
                    block[(l - 1) / blocksize][2 * r]++;
            }
        }
    }
    return 0;
}
