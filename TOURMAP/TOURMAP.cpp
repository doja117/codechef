#include <iostream>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int result = 0;
        map<string, int> parity;
        map<string, string> cost, path;
        for(int i = 1; i < n; i++) {
            string s1, s2, s3;
            cin >> s1 >> s2 >> s3;
            result += stoi(s3);
            parity[s1] += 1;
            parity[s2] -= 1;
            cost[s1] = s3;
            path[s1] = s2;
        }
		string start;
        for(auto it = parity.begin(); it != parity.end(); it++) {
            if(it->second == 1) {
                start = it->first;
            }
        }
        while(path.find(start) != path.end()) {
            cout << start << ' ' << path[start] << ' ' << cost[start] << endl;
            start = path[start];
        }
        cout << result << "$\n";
    }
    return 0;
}
