#include <iostream>
#include <cmath>
#include <complex>
#include <iomanip>
using namespace std;

void giai_phuong_trinh_bac_hai(double a, double b, double c) {
    if (a == 0) {
        cout << "He so a phai khac 0." << endl;
        return;
    }

    double delta = b * b - 4 * a * c;
    cout << fixed << setprecision(2);
    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);

        cout  << x2 << endl;
        cout  << x1 << endl;
    } else if (delta == 0) {
        double x = -b / (2 * a);

        cout  << x << endl;
    } else {
        complex<double> x1 = complex<double>(-b, sqrt(-delta)) / (2.0 * a);
        complex<double> x2 = complex<double>(-b, -sqrt(-delta)) / (2.0 * a);

       cout  << x2.real() <<" "<<x2.imag()<< endl;
        cout << x1.real() <<" "<<x1.imag() << endl;
    }
}

int main() {
    double a, b, c;
    cin>>a>>b>>c;

    giai_phuong_trinh_bac_hai(a, b, c);

    return 0;
}
