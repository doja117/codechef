#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q, y, x;
    cin >> n >> q;
    int row[n], column[n];
    fill(row, row + n, 0);
    fill(column, column + n, 0);
    for(string op; cin >> op >> y >> x; ) {
        switch(op[0]) {
            case 'R':
                row[y - 1] += x;
                break;
            case 'C':
                column[y - 1] += x;
                break;
        }
    }
    cout << *max_element(row, row + n) + *max_element(column, column + n);
    return 0;
}
