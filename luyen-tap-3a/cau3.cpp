#include <iostream>
using namespace std;

int n;
string s;

void Try(int i) {
    for (int i = 0; i <= 1; ++i) {
        s += to_string(i);
        int len = s.length();
        if (len == n) {
            cout << s << '\n';
        } else {
            Try(i + 1);
        }
        s.pop_back();
    }
}

int main() {
    cin >> n;
    Try(1);
    return 0;
}