#include <iostream>

using namespace std;


int main() {
    int n; cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        int value = i;
        for (int j = 1; j <= n; ++j) {
            int x = value % n;
            if (x == 0) {
                cout << n << ' ';
            } else {
                cout << x << ' ';
            }
            value += 1;
        }
        cout << '\n';
    }

    return 0;
}