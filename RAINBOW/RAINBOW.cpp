#include <iostream>
#include <set>
#include <list>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int c[n][n];
        list<int> interesting;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> c[i][j];
            }
            interesting.emplace_back(i);
        }
        bool removed;
        do {
            removed = false;
            for(auto it = interesting.begin(); it != interesting.end(); it++) {
                set<int> color;
                for(auto& i : interesting) {
                    if(*it != i) {
                        color.emplace(c[*it][i]);
                    }
                }
                if(color.size() <= 1) {
                    it = interesting.erase(it);
                    removed = true;
                }
            }
        } while(removed);
        cout << interesting.size() << endl;
    }
    return 0;
}
