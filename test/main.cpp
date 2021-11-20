#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> rotate(vector<int>& nums, int k) {
    size_t n { nums.size() };
    
    vector<int> c (n);
    k %= n;
    
    size_t idx { 0 };
    
    for (size_t i { nums.size() - k }; i < nums.size(); i++)
        c[idx++] = nums[i];
        
    for (size_t i { 0 }; i < nums.size() - k; i++)
        c[idx++] = nums[i];
    
    nums = c;
    
    return nums;
}

int main() {
    vector<int> nums { 1, 2, 3 };
    for (int x: rotate(nums, 101)) {
        cout << x << ' ';
    }
    return 0;
}