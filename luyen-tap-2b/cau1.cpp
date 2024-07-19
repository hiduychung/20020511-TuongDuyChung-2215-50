#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e6;

int a[maxN];


int main() {
    int n; cin >> n; 
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a, a + n);
    
    int waitTime = a[0];
    int res = a[0];
    
    for (int i = 1; i < n - 1; ++i) {
        int val = a[i] + waitTime;
        res += val;
        waitTime += a[i];
    }
    
    cout << res;

    return 0;
}