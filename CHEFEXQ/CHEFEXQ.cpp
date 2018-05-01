#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int SIZE = 1000001;

int sqrt(int n) {
    auto begin = 0, end = n;
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
    int n, q;
    cin >> n >> q;
    int a[n], blocksize = sqrt(n), blockcount = (n - 1) / blocksize + 1, xorr[blockcount];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int block[blockcount][SIZE];
    for(int i = 0; i < blockcount; i++) {
        xorr[i] = 0;
        fill(block[i], block[i] + SIZE, 0);
        for(int j = i * blocksize; j < min(n, (i + 1) * blocksize); j++) {
            xorr[i] ^= a[j];
            block[i][xorr[i]]++;
        }
    }
    for(int t, i, k; cin >> t >> i >> k; ) {
        i--;
        int current = 0, blocknum = i / blocksize;
        switch(t) {
            case 1:
                for(int j = blocknum * blocksize; j < min(n, (blocknum + 1) * blocksize); j++) {
                    current ^= a[j];
                    block[blocknum][current]--;
                }
                a[i] = k;
                current = 0;
                for(int j = blocknum * blocksize; j < min(n, (blocknum + 1) * blocksize); j++) {
                    current ^= a[j];
                    block[blocknum][current]++;
                }
                xorr[blocknum] = current;
                break;
            case 2:
                int result = 0;
                for(int i = 0; i < blocknum; i++) {
                    result += block[i][current ^ k];
                    current ^= xorr[i];
                }
                for(int j = blocknum * blocksize; j <= i; j++) {
                    current ^= a[j];
                    if(current == k) {
                        result++;
                    }
                }
                cout << result << endl;
        }
    }
    return 0;
}
