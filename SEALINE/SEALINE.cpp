#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        forward_list<int> list;
        int result = 0;
        for(int a, i = 1; i <= n; i++) {
            cin >> a;
            if(a != 0) {
                int current = 1;
                for(auto it = list.begin(); it != list.end(); it++) {
                    if(*it == a) {
                        result += min(current, i - current - 1);
                        list.insert_after(it, i);
                        break;
                    }
                    current++;
                }
            } else {
                list.emplace_front(i);
            }
        }
        cout << result << endl;
    }
    return 0;
}
