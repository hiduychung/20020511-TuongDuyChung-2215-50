#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    
    for (int i = 0; i < len; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int left = i + 1, right = len - 1;
        while (left < right) {
            int total = nums[i] + nums[left] + nums[right];
            if (total == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;
                ++left;
                --right;
            } else if (total < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }
    
    return result;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n, 0);
    
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<vector<int>> ans = threeSum(nums);
    
    for (vector<int> v : ans) {
        for (int x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
