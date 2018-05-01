
#include <iostream>
#include <map>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, F; cin >> N >> F; ) {
        int result = 0;
        map<int, int> count;
        for(int i = 0; i < N; i++) {
            int H;
            cin >> H;
            count[H]++;
        }
        for(auto& i : count) {
            for(long long j = F; j <= i.first; j *= F) {
                if(i.first % j == 0) {
                    auto find = count.find(i.first / j);
                    if(find != count.end()) {
                        result += find->second * i.second;
                    }
                }
            }
            result += i.second * (i.second - 1) / 2;
        }
        cout << result << endl;
    }
    return 0;
}
