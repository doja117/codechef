#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int N, result = 0;
    cin >> N;
    bitset<2000> bits[N];
    string graph[N];
    for(int i = 0; cin >> graph[i]; i++) {
        bits[i] = bitset<2000>(graph[i]);
    }
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(graph[i][j] == '0' && (bits[i] & bits[j]).any()) {
                result++;
            }
        }
    }
    cout << 2 * result;
    return 0;
}  
