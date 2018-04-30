#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        auto find1 = s.find("010"), find2 = s.find("101");
        if(find1 == string::npos && find2 == string::npos) {
            cout << "Bad\n";
        } else {
            cout << "Good\n";
        }
    }
    return 0;
}
