#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int R, C; cin >> R >> C; ) {
        string m[R], result = "There is indeed no spoon!\n";
        for(int i = 0; i < R; i++) {
            cin >> m[i];
        }
        for(int i = 0; i < R; i++) {
            for(int j = 0; j + 4 < C; j++) {
                if(tolower(m[i][j]) == 's' && tolower(m[i][j + 1]) == 'p' && tolower(m[i][j + 2]) == 'o' && tolower(m[i][j + 3]) == 'o' && tolower(m[i][j + 4]) == 'n') {
                    result = "There is a spoon!\n";
                }
            }
        }
        for(int i = 0; i < C; i++) {
            for(int j = 0; j + 4 < R; j++) {
                if(tolower(m[j][i]) == 's' && tolower(m[j + 1][i]) == 'p' && tolower(m[j + 2][i]) == 'o' && tolower(m[j + 3][i]) == 'o' && tolower(m[j + 4][i]) == 'n') {
                    result = "There is a spoon!\n";
                }
            }
        }
        cout << result;
    }
    return 0;
}
