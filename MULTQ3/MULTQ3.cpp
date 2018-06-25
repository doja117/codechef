#include <cstdio>
#include <algorithm>
using namespace std;

int* a, n, q, blocksize, **block, *mark;

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

int query(int begin, int end) {
    int result = 0;
    for(int i = begin; i < end; i++) {
        if(a[i] == mark[i / blocksize]) {
            result++;
        }
    }
    return result;
}

void update(int begin, int end) {
    for(int i = begin; i < end; i++) {
        a[i] = (a[i] + 1) % 3;
    }
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
    int blocknum = (n - 1) / blocksize + 1;
    block = new int*[blocknum];
    mark = new int[blocknum]();
    a = new int[n]();
    for(int i = 0; i < blocknum; i++) {
        block[i] = new int[3];
        block[i][0] = min(blocksize, n - i * blocksize);
        block[i][1] = 0;
        block[i][2] = 0;
    }
    for(int m, l, r; scanf("%d %d %d", &m, &l, &r) > 0; ) {
        int start = l / blocksize + 1, end = r / blocksize;
        switch(m) {
            case 0:
                if(end <= start) {
                    update(l, r + 1);
                } else {
                    update(l, start * blocksize);
                    for(int i = start; i < end; i++) {
                        mark[i] = (mark[i] + 2) % 3;
                    }
                    update(end * blocksize, r + 1);
                }
                update(l / blocksize);
                update(r / blocksize);
                break;
            case 1:
                int result = 0;
                if(end <= start) {
                    result += query(l, r + 1);
                } else {
                    result += query(l, start * blocksize);
                    for(int i = start; i < end; i++) {
                        result += block[i][mark[i]];
                    }
                    result += query(end * blocksize, r + 1);
                }
                printf("%d\n", result);
        }
    }
    return 0;
}
