#include <iostream>
using namespace std;

int main() {
    for(int A, B; cin >> A >> B; ) {
        auto result = to_string(A - B);
        if(result.back() == '9') {
            result.back() = '8';
        } else {
            result.back()++;
        }
        cout << result << endl;
    }
    return 0;
}
