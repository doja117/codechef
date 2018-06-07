#include <iostream>
using namespace std;

int main() {
    int x, y, r;
    scanf("%d %d.%d", &x, &y, &r);
    x *= 100;
    y = y * 100 + r;
    if(x % 500 == 0 && y > x + 50) {
        y = y - x - 50;
    }
    printf("%d.%.2d", y / 100, y % 100);
    return 0;
}
