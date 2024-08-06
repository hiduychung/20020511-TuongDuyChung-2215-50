#include <iostream>
using namespace std;

int fac(int n) {
    if (n == 0) return 1;
    return n * fac(n - 1);
}

int nCk(int n, int k) {
    return fac(n) / (fac(k) * (fac(n - k)));
}

int main() {
    int n; cin >> n;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << nCk(i, j) << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}