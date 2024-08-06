#include <iostream>
#include <vector>
using namespace std;



int main() {
    int n; cin >> n;
    vector<int> a(n, 0);
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int m; cin >> m;
    vector<int> b(m, 0);
    
    for (int i = 0; i < m; ++i) cin >> b[i];
    
    int index = 0;
    
    bool flag = false;
    
    for (int i = 0; i < m; ++i) {
        if (b[i] == a[index]) {
            index ++;
        } else if (b[i] == a[0]) {
            index = 1;
        } else {
            index = 0;
        }
        
        if (index == n) {
            flag = true;
            break;
        }
        
    }
    
    if (flag) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}