#include <iostream>
#include <array>
using namespace std;

array<long long, 3> *prefixmod;
int *blocksum, *divisible;
string s;

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

void update(int i, int begin, int end) {
    prefixmod[i] = {1, 0, 0};
    blocksum[i] = 0;
    divisible[i] = 0;
    for(int j = begin; j < end; j++) {
        blocksum[i] = (blocksum[i] + s[j]) % 3;
        divisible[i] += prefixmod[i][blocksum[i]];
        prefixmod[i][blocksum[i]]++;
    }
    prefixmod[i][0]--;
}

int main() {
    int n, m;
    cin >> n >> m;
    cin >> s;
    for(auto& i : s) {
        i = i - '0';
    }
    int blocksize = sqrt(n), blockcount = (n - 1) / blocksize + 1;
    blocksum = new int [blockcount];
    divisible = new int [blockcount];
    prefixmod = new array<long long, 3>[blockcount];
    for(int i = 0; i < blockcount; i++) {
        update(i, i * blocksize, min(i * blocksize + blocksize, n));
    }
    for(int a, b, c; cin >> a >> b >> c; ) {
        auto i = (b - 1) / blocksize;
        switch(a) {
            case 1:
                s[b - 1] = c;
                update(i, i * blocksize, min(i * blocksize + blocksize, n));
                break;
            case 2:
                array<long long, 3> mod = {1, 0, 0};
                long long result = 0;
                int start = i + 1, end = c / blocksize;
                if(end <= start) {
                    for(int j = b - 1, sum = 0; j < c; j++) {
                        sum = (sum + s[j]) % 3;
                        result += mod[sum];
                        mod[sum]++;
                    }
                } else {
                    for(int j = start * blocksize - 1, sum = 0; j >= b - 1; j--) {
                        sum = (sum + s[j]) % 3;
                        result += mod[sum];
                        mod[sum]++;
                    }
                    mod[0]--;
                    for(int j = start; j < end; j++) {
                        result += divisible[j];
                        result += mod[0] * prefixmod[j][0] + mod[1] * prefixmod[j][2] + mod[2] * prefixmod[j][1];
                        auto copy = mod;
                        mod = {0, 0, 0};
                        for(int k = 0; k < 3; k++) {
                            mod[(k + blocksum[j]) % 3] += copy[k];
                            mod[k] += prefixmod[j][(3 + blocksum[j] - k) % 3];
                        }
                        mod[0]--;
                        mod[blocksum[j]]++;
                    }
                    array<long long, 3> last = {1, 0, 0};
                    for(int j = end * blocksize, sum = 0; j < c; j++) {
                        sum += s[j];
                        result += last[sum % 3];
                        last[sum % 3]++;
                    }
                    result += mod[0] * (last[0] - 1) + mod[1] * last[2] + mod[2] * last[1];
                }
                cout << result << endl;
        }
    }
    return 0;
}
