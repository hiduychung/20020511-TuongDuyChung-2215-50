#include <iostream>

using namespace std;

bool checkString(string s) {
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
    string s; cin >> s;
    
    cout << (checkString(s) ? "Yes" : "No");
    
    return 0;
}