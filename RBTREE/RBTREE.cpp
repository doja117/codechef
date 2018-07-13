#include <iostream>
using namespace std;

int depth(int x) {
    int result = 0;
    for(int i = 2; i <= x; i *= 2) {
        result++;
    }
    return result;
}

int main() {
    int q, color = 0;
    cin >> q;
    for(string q; cin >> q; ) {
        switch(q[1]) {
            case 'i':
                color = 1 - color;
                break;
            case 'r':
            case 'b':
                int x, y, result = 0, target = q[1] == 'r';
                cin >> x >> y;
                int dx = depth(x), dy = depth(y);
                while(x != y) {
                    if(x > y) {
                        x /= 2;
                        if((dx + color) % 2 == target) {
                            result++;
                        }
                        dx--;
                    } else {
                        y /= 2;
                        if((dy + color) % 2 == target) {
                            result++;
                        }
                        dy--;
                    }
                }
                if((dx + color) % 2 == target) {
                    result++;
                }
                cout << result << endl;
        }
    }
    return 0;
}
