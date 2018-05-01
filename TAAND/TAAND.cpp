#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; cin >> A[i]; i++) {
    }
    for(int i = 1 << 30; i > 0; i /= 2) {
        vector<int> current;
        for(int j : A) {
            if(j / i % 2 != 0) {
                current.emplace_back(j);
            }
        }
        if(current.size() >= 2) {
            A = current;
        }
    }
    cout << (A[0] & A[1]); 
    return 0;
}
