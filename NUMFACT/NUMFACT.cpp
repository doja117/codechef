#include <iostream>
#include <map>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        map<int, int> pow;
        int result = 1;
        for(int A; N > 0; N--) {
            cin >> A;
            for(int i = 2; i * i <= A; i++) {
                int count = 0;
                while(A % i == 0) {
                    count++;
                    A /= i;
                }
                pow[i] += count;
            }
            if(A > 1) {
            	pow[A]++;
            }
        }
        for(auto& i : pow) {
            result *= i.second + 1;
        }
        cout << result << endl;
    }
    return 0;
} 
