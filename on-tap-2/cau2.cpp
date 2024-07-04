#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minAbsoluteDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());


    int min_diff = INT_MAX;


    for (size_t i = 0; i < arr.size() - 1; ++i) {
        int diff = abs(arr[i] - arr[i + 1]);
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    return min_diff;
}

int main() {

    int n;
    cin>>n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int result = minAbsoluteDifference(numbers);
    cout  << result << endl;

    return 0;
}
