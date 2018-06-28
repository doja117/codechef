#include <iostream>
#include <bitset>
using namespace std;

const int BLOCKSIZE = 64;

int main() {
    int T;
    cin >> T;
    for(int n, k; cin >> n >> k; ) {
        int blocknum = (n - 1) / BLOCKSIZE + 1, result = 0;
        bitset<BLOCKSIZE> block[blocknum];
        string s;
        cin >> s;
        for(int i = 0; i < blocknum; i++) {
            for(int j = i * BLOCKSIZE; j < min(n, (i + 1) * BLOCKSIZE); j++) {
                block[i][j % BLOCKSIZE] = (s[j] == 'R');
            }
        }
        for(int i = 0; i < n; i++) {
            if(block[i / BLOCKSIZE][i % BLOCKSIZE]) {
                int r = min(i + k - 1, n - 1), start = i / BLOCKSIZE + 1, end = r / BLOCKSIZE;
                if(end <= start) {
                    for(int j = i; j <= r; j++) {
                        block[j / BLOCKSIZE].flip(j % BLOCKSIZE);
                    }
                } else {
                    for(int j = i; j < start * BLOCKSIZE; j++) {
                        block[j / BLOCKSIZE].flip(j % BLOCKSIZE);
                    }
                    for(int j = start; j < end; j++) {
                        block[j].flip();
                    }
                    for(int j = end * BLOCKSIZE; j <= r; j++) {
                        block[j / BLOCKSIZE].flip(j % BLOCKSIZE);
                    }
                }
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
