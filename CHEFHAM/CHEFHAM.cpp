#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; cout << endl) {
        int a[n], b[n], result = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        list<int> list(a, a + n);
        for(int i = 0; i < n; i++) {
            for(auto it = list.begin(); it != list.end(); it++) {
                if(*it != a[i]) {
                    b[i] = *it;
                    list.erase(it);
                    result++;
                    break;
                }
            }
            if(b[i] == a[i]) {
                for(int j = 0; j < i; j++) {
                    if(b[j] != a[i] && b[i] != a[j]) {
                        swap(b[j], b[i]);
                        result++;
                        break;
                    }
                }
                list.erase(list.begin());
            }
        }
        cout << result << endl;
        for(int i = 0; i < n; i++) {
            cout << b[i] << ' ';
        }
    }
    return 0;
} 
