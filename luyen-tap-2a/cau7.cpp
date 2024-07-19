#include <iostream>

using namespace std;

const int maxN = 1e7;

int main() {
    int n; cin >> n;
    
    int min_row = maxN;
    int min_col = maxN;
    
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        min_row = min(x, min_row);
        min_col = min(y, min_col);
    }
    
    cout << min_col * min_row;

    return 0;
}