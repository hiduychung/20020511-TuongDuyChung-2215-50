#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

const int maxN = 1000007;
vector<bool> v(maxN + 1, false);

void sang() {
    for (int i = 2; i <= maxN; ++i) {
        v[i] = true;
    }
    
    for (int i = 2; i <= sqrt(maxN); ++i) {
        if (v[i]) {
            for (int j = i*i; j <= maxN; j += i) {
                v[j] = false;
            }
        }
    }
}

int main() {
    sang();
    
    int n; cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (v[x]) {
            cout << x << ' ';
        }
    }
    
    return 0;
}