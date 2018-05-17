#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        vector<int> fingers(n), gloves(n);
        for(int i = 0; i < n; i++) {
            cin >> fingers[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> gloves[i];
        }
        string result = "both\n";
        for(int i = 0; i < n; i++) {
            if(fingers[i] > gloves[i]) {
                result = "back\n";
            }
        }
        for(int i = 0; i < n; i++) {
            if(fingers[i] > gloves.rbegin()[i]) {
                if(result != "back\n") {
                    result = "front\n";
                } else {
                    result = "none\n";
                }
                break;
            }
        }
        cout << result;
    }
    return 0;
}
