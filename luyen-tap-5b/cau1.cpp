#include <iostream>
#include <vector>
// #include <pair>
using namespace std;

const int maxN = 1000;
char a[maxN][maxN];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
            
            
    vector<pair<int, int>> moves = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int count = 0;
            if (a[i][j] == '.') {
                for (auto it : moves) {
                    int x = i + it.first;
                    int y = j + it.second;
                    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '*')
                        count += 1;
                }
                a[i][j] = char(count + 48);
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}