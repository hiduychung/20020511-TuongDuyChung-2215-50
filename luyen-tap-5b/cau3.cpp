#include <iostream>
#include <vector>
using namespace std;

const int maxN = 20;
char a[maxN][maxN];
int c[maxN][maxN];


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<pair<int, int>> moves = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            c[i][j] = -1;   
        }
        
    bool flag = true;
    
    int x, y;
    
    while (cin >> x >> y) {
        
        if (a[x][y] == 'M' && flag) {
            cout << "YOU ARE DEAD! \n";
            
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << a[i][j] << ' ';
                }
                cout << '\n';
            }
            
            flag = false;
        }
        
        if (flag) {
            c[x][y] = 0;
            
            for (auto it : moves) {
                int ix = x + it.first;
                int iy = y + it.second;
                
                if (ix >= 0 && ix < n && iy >= 0 && iy < m && a[ix][iy] == 'M')
                    c[x][y] += 1;
            }
            
            
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << c[i][j] << ' ';
                }
                cout << '\n';
            }
        }
    }
    
    return 0;
}