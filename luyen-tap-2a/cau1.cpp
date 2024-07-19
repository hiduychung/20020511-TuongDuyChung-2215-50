#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1000;
int a[maxN];

int main() {
    int n; cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int maxLen = 0;
    int len = 1;
    
    sort(a, a + n);
    
    int firstVal = a[0];
    
    for (int i = 1; i < n; ++i) {
        if (a[i] - firstVal <= 1) {
            len += 1;
        } else {
            maxLen = max(maxLen, len);
            len = 1;
            firstVal = a[i];
        }
    }
    
    maxLen = max(maxLen, len);
    
    cout << maxLen;

    return 0;
}