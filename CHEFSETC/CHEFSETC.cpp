#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int set[4]; cin >> set[0] >> set[1] >> set[2] >> set[3]; ) {
        string result = "No\n";
        for(int i = 1; i < 16; i++) {
            bitset<4> bit(i);
            int sum = 0;
            for(int j = 0; j < 4; j++) {
                if(bit[j]) {
                    sum += set[j];
                }
            }
            if(sum == 0) {
                result = "Yes\n";
                break;
            }
        }
        cout << result;
    }
    return 0;
}
