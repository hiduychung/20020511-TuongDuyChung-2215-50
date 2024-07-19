#include <iostream>
#include <math.h>

using namespace std;

int countDiv(int a) {
    int count = 0;
    int val = a;
    
    while (a) {
        int digit = a % 10;
        
        if (digit && val % digit == 0) {
            count += 1;
        }
        
        a /= 10;
    }
    
    return count;
}

int main() {
    int n; cin >> n;
    
    while(n --) {
        int a; cin >> a;
        
        cout << countDiv(a) << '\n';
    }

    return 0;
}