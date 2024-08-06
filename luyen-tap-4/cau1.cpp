#include <iostream>
#include <algorithm>

using namespace std;

// Hàm tìm ước chung lớn nhất
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int tu, mau;
    cin >> tu >> mau;

    int ucln = gcd(abs(tu), abs(mau));

    // Tối giản phân số
    tu /= ucln;
    mau /= ucln;

    // Đảm bảo mẫu số luôn dương
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }

    if (mau == 1) {
        cout << tu << endl;
    } else {
        cout << tu << "/" << mau << endl;
    }

    return 0;
}
