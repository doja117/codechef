#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for(int n; scanf("%d", &n) > 0; ) {
        bool positive = false, negative = false;
        for(int u, v; n > 0; n--) {
            scanf("%d %d", &u, &v);
            auto diff = u - v;
            if(diff > 0) {
                positive = true;
            } else if(diff < 0) {
                negative = true;
            } else {
                positive = true;
                negative = true;
            }
        }
        if(positive && negative) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
