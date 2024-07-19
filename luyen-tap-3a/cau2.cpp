#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool binarySearch(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int n;
    int m;
    cin>>n>>m;
    int number[n];
    int number1[m];

    for(int i=0;i<n;i++){
        cin>>number[i];
    }
    for(int j=0;j<m;j++){
        cin>>number1[j];
        if (binarySearch(number, n, number1[j])) {
    cout << "YES"<<" ";
        } else {
    cout << "NO"<<" ";
}
    }


    return 0;
}
