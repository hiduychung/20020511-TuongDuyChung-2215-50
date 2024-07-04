#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int n;

    cin >> n;



    vector<double> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    double min_val = numeric_limits<double>::max();
    double max_val = numeric_limits<double>::lowest();

    for (int i = 0; i < n; ++i) {
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
    }

    cout  << max_val << endl;
    cout  << min_val << endl;

    return 0;
}
