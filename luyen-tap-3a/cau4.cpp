#include <iostream>
using namespace std;

int n, m;
string s;

bool check(string s) {
    int len = s.length();
    int countN = 0, countM = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '0') countN ++;
        else countM ++;
    }
    return countN == n && countM == m;
}

void Try(int i) {
    for (int i = 0; i <= 1; ++i) {
        s += to_string(i);
        int len = s.length();
        if (len == n + m) {
            if (check(s))
                cout << s << '\n';
        } else {
            Try(i + 1);
        }
        s.pop_back();
    }
}

int main() {
    cin >> n >> m;
    Try(1);
    return 0;
}