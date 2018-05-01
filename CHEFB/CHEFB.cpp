#include <iostream>
#include <map>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int result = 0;
        map<int, int> exponent;
        for(int i = 0; i < N; i++) {
            int A;
            cin >> A;
            for(int j = 2; j * j <= A; j++) {
                int count = 0;
                while(A % j == 0) {
                    count++;
                    A /= j;
                }
                if(count > 0) {
                    auto find = exponent.find(j);
                    if(find == exponent.end()) {
                        exponent[j] = count;
                    } else {
                        find->second = max(find->second, count);
                    }
                }
            }
            if(A > 1) {
                auto find = exponent.find(A);
                if(find == exponent.end()) {
                    exponent[A] = 1;
                }
            }
        }
        for(auto& i : exponent) {
            result += i.second;
        }
        cout << result << endl;
    }
    return 0;
}
