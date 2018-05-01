#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string k; cin >> k; cout << k) {
        for(int i = k.size() - 1; i >= 0; i--) {
            if(k[i] == '9') {
                k[i] = '0';
            } else {
                k[i]++;
                break;
            }
        }
        if(k[0] == '0') {
            k = "1" + k;
        }
        for(int i = (k.size() - 1) / 2; i >= 0; i--) {
            if(k[i] < k.rbegin()[i]) {
                for(int j = (k.size() - 1) / 2; j >= 0; j--) {
                    if(k[j] == '9') {
                        k[j] = '0';
                    } else {
                        k[j]++;
                        break;
                    }
                }
                break;
            } else if(k[i] > k.rbegin()[i]) {
                break;
            }
        }
        for(int i = (k.size() - 1) / 2; i >= 0; i--) {
            k.rbegin()[i] = k[i];
        }
        k.push_back('\n');
    }
    return 0;
}
