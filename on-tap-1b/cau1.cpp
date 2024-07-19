#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int num;

    // Đọc đầu vào từ bàn phím
    while (cin >> num) {
        numbers.push_back(num);
        if (num < 0) break;
    }

    // Xử lý dãy số và loại bỏ các số trùng nhau liên tiếp
    vector<int> result;
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i == 0 || numbers[i] != numbers[i-1]) {
            result.push_back(numbers[i]);
        }
        if (numbers[i] < 0) break;
    }

    // In kết quả
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
