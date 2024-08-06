#include <algorithm>

string decimal_to_binary(long number)
{
    // Your code here
    
    if (number == 0) return "0";
    
    string s = "";
    for (long i = number; i > 0; i = (i >> 1)) {
        s += to_string(i & 1);
    }
    
    reverse(s.begin(), s.end());
    
    return s;
}