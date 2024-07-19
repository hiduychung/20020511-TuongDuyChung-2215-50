#include <iostream>

using namespace std;

bool checkNumber(string s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left <= right) {
        if (s[left] != s[right]) 
            return false;
        left ++;
        right --;
    }
    
    return true;
}

int main() {
    int test; cin >> test;
    
    while (test --) {
        int a, b; cin >> a >> b;
        
        int ans = 0;
        
        for (int i = a; i <= b; ++i) {
            if (checkNumber(to_string(i)))
                ans += 1;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}