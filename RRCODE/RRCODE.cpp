#include <iostream>
using namespace std;

template<class BinaryOperation>
int F(int n, int k, int answer, int a[], BinaryOperation binary_op) {
    if(k == 0 || (binary_op(1, 1) == 0 && k % 2 == 0)) {
        return answer;
    }
    for(int j = 0; j < n; j++) {
        answer = binary_op(answer, a[j]);
    }
    return answer;
}

int main() {
    int T;
    cin >> T;
    for(int n, k, answer; cin >> n >> k >> answer; cout << endl) {
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string op;
        cin >> op;
        switch(op[0]) {
            case 'A':
                cout << F(n, k, answer, a, bit_and<int>());
                break;
            case 'X':
                cout << F(n, k, answer, a, bit_xor<int>());
                break;
            case 'O':
                cout << F(n, k, answer, a, bit_or<int>());
        }
    }
    return 0;
}
