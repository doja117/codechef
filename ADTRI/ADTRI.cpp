#include <cstdio>
#include <stack>
#include <array>
using namespace std;

const int SIZE = 5000001;

int main() {
    int t;
    scanf("%d", &t);
    bool table[SIZE] = {};
    stack<array<int, 3>> stack;
    stack.emplace(array<int, 3> {3, 4, 5});
    do {
        auto top = stack.top();
        for(int j = 1; j * top[2] < SIZE; j++) {
            table[j * top[2]] = true;
        }
        stack.pop();
        auto c1 = array<int, 3> {top[0] - 2 * top[1] + 2 * top[2], 2 * top[0] - top[1] + 2 * top[2], 2 * top[0] - 2 * top[1] + 3 * top[2]};
        auto c2 = array<int, 3> {top[0] + 2 * top[1] + 2 * top[2], 2 * top[0] + top[1] + 2 * top[2], 2 * top[0] + 2 * top[1] + 3 * top[2]};
        auto c3 = array<int, 3> {-top[0] + 2 * top[1] + 2 * top[2], -2 * top[0] + top[1] + 2 * top[2], -2 * top[0] + 2 * top[1] + 3 * top[2]};
        if(c1[2] < SIZE) {
            stack.emplace(c1);
        }
        if(c2[2] < SIZE) {
            stack.emplace(c2);
        }
        if(c3[2] < SIZE) {
            stack.emplace(c3);
        }
    } while(!stack.empty());
    for(int n; scanf("%d", &n) > 0; ) {
        if(table[n]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
