#include <iostream>
#include <vector>

using namespace std;

void solve(int n) {
    vector<vector<int>> arr(n, vector<int>(n, 0));

    int a = 0, b = n / 2;

    for (int i = 1; i <= n * n; ++i) {
        arr[a][b] = i;
        int indexI = (a - 1 + n) % n;
        int indexJ = (b + 1) % n;

        if (arr[indexI][indexJ] != 0) { 
            a = (a + 1) % n;
        } else {
            a = indexI;
            b = indexJ;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n; cin >> n;
    
    solve(n);

    return 0;
}
