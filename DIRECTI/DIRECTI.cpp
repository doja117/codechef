#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; cout << endl) {
        cin.ignore(1, '\n');
        string lines[n];
        for(int i = 0; i < n; i++) {
            getline(cin, lines[i]);
        }
        cout << "Begin on ";
        if(lines[n - 1].front() == 'L') {
            cout << lines[n - 1].substr(8, lines[n - 1].size()) << endl;
        } else {
            cout << lines[n - 1].substr(9, lines[n - 1].size()) << endl;
        }
        for(int i = n - 1; i >= 1; i--) {
            if(lines[i].front() == 'L') {
                cout << "Right on ";
            } else {
                cout << "Left on ";
            }
            if(lines[i - 1].front() == 'L') {
                cout << lines[i - 1].substr(8, lines[i - 1].size()) << endl;
            } else {
                cout << lines[i - 1].substr(9, lines[i - 1].size()) << endl;
            }
        }
    }
    return 0;
}
