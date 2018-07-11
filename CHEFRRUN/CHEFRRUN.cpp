#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<bool> visited(n);
        int result = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                int p1 = (i + a[i] + 1) % n, p2 = (p1 + a[p1] + 1) % n;
                while(p1 != p2) {
                    if(visited[p1]) {
                        for(p2 = i; p2 != p1; p2 = (p2 + a[p2] + 1) % n) {
                            visited[p2] = true;
                        }
                        p2 = i;
                        break;
                    }
                    p1 = (p1 + a[p1] + 1) % n;
                    p2 = (p2 + a[p2] + 1) % n;
                    p2 = (p2 + a[p2] + 1) % n;
                }
                p1 = i;
                while(p1 != p2) {
                    visited[p1] = true;
                    p1 = (p1 + a[p1] + 1) % n;
                    p2 = (p2 + a[p2] + 1) % n;
                }
                if(!visited[p1]) {
                    do {
                        visited[p1] = true;
                        p1 = (p1 + a[p1] + 1) % n;
                        result++;
                    } while(p1 != p2);
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
