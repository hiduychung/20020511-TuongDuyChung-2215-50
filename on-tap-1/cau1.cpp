#include <iostream>
#include <cmath>

using namespace std;

void kiem_tra_tam_giac(int a, int b, int c) {
    // Kiểm tra điều kiện bất đẳng thức tam giác
    if (a + b > c && a + c > b && b + c > a) {
        // Tính chu vi
        int chu_vi = a + b + c;

        // Kiểm tra loại tam giác
        string loai_tam_giac;
        if (a == b && b == c) {
            loai_tam_giac = "deu";
        } else if (a == b || b == c || a == c) {
            loai_tam_giac = "can";
        } else if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
            loai_tam_giac = "vuong";
        } else {
            loai_tam_giac = "thuong";
        }

        cout << chu_vi << endl;
        cout << loai_tam_giac << endl;
    } else {
        cout << "Invalid" << endl;
    }
}

int main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    kiem_tra_tam_giac(a, b, c);

    return 0;
}
