#include <iostream>
using namespace std;
 
string multiply(const string& a, const string& b) {
    string product(a.size() + b.size(), '0');
    for(int i = a.size() - 1; i >= 0; i--) {
        for(int j = b.size() - 1; j >= 0; j--) {
            auto sum = (a[i] - '0') * (b[j] - '0') + product[i + j + 1] - '0';
            product[i + j] += sum / 10;
            product[i + j + 1] = sum % 10 + '0';
        }
    }
    if(product.front() == '0') {
        product.erase(0, 1);
    }
    for(auto c : product) {
        if(c != '0') {
            return product;
        }
    }
    return "0";
}
 
int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        string result = "1";
        for(int i = 2; i <= n; i++) {
            result = multiply(result, to_string(i));
        }
        cout << result << endl;
    }
    return 0;
}
