#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, result = 0;
    cin >> N;
    int p[N];
    for(int i = 0; cin >> p[i]; i++) {
    }
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int sum = p[i] + p[j], current = 2;
            vector<bool> visited(N, false);
            visited[i] = true;
            visited[j] = true;
            for(int k = 0; k < N; k++) {
                if(!visited[k]) {
                    for(int l = k + 1; l < N; l++) {
                        if(!visited[l] && p[k] + p[l] == sum) {
                            visited[k] = true;
                            visited[l] = true;
                            current += 2;
                            break;
                        }
                    }
                }
            }
            result = max(result, current);
        }
    }
    cout << result;
    return 0;
}
