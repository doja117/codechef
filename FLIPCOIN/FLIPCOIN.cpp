#include <iostream>
#include <bitset>
using namespace std;

const int BLOCKSIZE = 64;

int main() {
    int n, q;
    cin >> n >> q;
    int blocknum = (n - 1) / BLOCKSIZE + 1;
    bitset<BLOCKSIZE> bit[blocknum];
    for(int m, a, b; cin >> m >> a >> b; ) {
        int start = a / BLOCKSIZE + 1, end = b / BLOCKSIZE;
        switch(m) {
            case 0:
                if(end <= start) {
                    for(int i = a; i <= b; i++) {
                        bit[i / BLOCKSIZE].flip(i % BLOCKSIZE);
                    }
                } else {
                    for(int i = a; i < start * BLOCKSIZE; i++) {
                        bit[i / BLOCKSIZE].flip(i % BLOCKSIZE);
                    }
                    for(int i = start; i < end; i++) {
                        bit[i].flip();
                    }
                    for(int i = end * BLOCKSIZE; i <= b; i++) {
                        bit[i / BLOCKSIZE].flip(i % BLOCKSIZE);
                    }
                }
                break;
            case 1:
                int result = 0;
                if(end <= start) {
                    for(int i = a; i <= b; i++) {
                        result += bit[i / BLOCKSIZE][i % BLOCKSIZE];
                    }
                } else {
                    for(int i = a; i < start * BLOCKSIZE; i++) {
                        result += bit[i / BLOCKSIZE][i % BLOCKSIZE];
                    }
                    for(int i = start; i < end; i++) {
                        result += bit[i].count();
                    }
                    for(int i = end * BLOCKSIZE; i <= b; i++) {
                        result += bit[i / BLOCKSIZE][i % BLOCKSIZE];
                    }
                }
                cout << result << endl;
        }
    }
    return 0;
}
