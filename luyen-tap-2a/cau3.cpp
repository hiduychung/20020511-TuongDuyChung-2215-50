#include <iostream>
#include <math.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return abs(gcd(b, a % b));
}

int main() {
    int a, b; cin >> a >> b;
    
    bool nev = false;
    if (a * b < 0) nev = true;
    
    int c = gcd(a, b);
    
    a /= c;
    a = abs(a);
    b /= c;
    b = abs(b);
    
    if (nev) 
        cout << '-';
    
    cout << a;
    
    if (b != 1) 
        cout << '/' << b;

    return 0;
}