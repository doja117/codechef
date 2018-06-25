#include <cstdio>
#include <algorithm>
using namespace std;

int* a, n, q, blocksize, **block;

int sqrt(int n) {
    int begin = 0, end = n;
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

void update(int i) {
    block[i][0] = 0;
    block[i][1] = 0;
    block[i][2] = 0;
    for(int j = i * blocksize; j < min((i + 1) * blocksize, n); j++) {
        block[i][a[j]]++;
    }
}

int main() {
    scanf("%d %d", &n, &q);
    blocksize = sqrt(n);
    int blocknum = (n - 1) / blocksize + 1, mark[blocknum];
    block = new int*[blocknum];
    a = new int[n]();
    for(int i = 0; i < blocknum; i++) {
        block[i] = new int[3];
        block[i][0] = min(blocksize, n - i * blocksize);
        block[i][1] = 0;
        block[i][2] = 0;
        mark[i] = 0;
    }
    for(int m, l, r; scanf("%d %d %d", &m, &l, &r) > 0; ) {
        int start = l / blocksize + 1, end = r / blocksize;
        switch(m) {
            case 0:
                if(end <= start) {
                    for(int i = l; i <= r; i++) {
                        a[i] = (a[i] + 1) % 3;
                    }
                } else {
                    for(int i = l; i < start * blocksize; i++) {
                        a[i] = (a[i] + 1) % 3;
                    }
                    for(int i = start; i < end; i++) {
                        mark[i] = (mark[i] + 2) % 3;
                    }
                    for(int i = end * blocksize; i <= r; i++) {
                        a[i] = (a[i] + 1) % 3;
                    }
                }
                update(l / blocksize);
                update(r / blocksize);
                break;
            case 1:
                int result = 0;
                if(end <= start) {
                    for(int i = l; i <= r; i++) {
                        if(a[i] == mark[i / blocksize]) {
                            result++;
                        }
                    }
                } else {
                    for(int i = l; i < start * blocksize; i++) {
                        if(a[i] == mark[i / blocksize]) {
                            result++;
                        }
                    }
                    for(int i = start; i < end; i++) {
                        result += block[i][mark[i]];
                    }
                    for(int i = end * blocksize; i <= r; i++) {
                        if(a[i] == mark[i / blocksize]) {
                            result++;
                        }
                    }
                }
                printf("%d\n", result);
        }
    }
    return 0;
}
