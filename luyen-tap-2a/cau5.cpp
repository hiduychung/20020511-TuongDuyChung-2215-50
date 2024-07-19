#include <iostream>
#include <math.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return abs(a / gcd(a, b) * b);
}

int main() {
    int a, b; cin >> a >> b;
    
    if (a * b == 0) {
        cout << 0;
    } else {
        cout << lcm(a, b);
    }

    return 0;
}