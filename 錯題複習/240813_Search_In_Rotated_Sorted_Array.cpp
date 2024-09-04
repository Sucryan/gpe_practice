#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        // Find the rotation index
        int rotationIndex = findRotationIndex(nums);
        
        // Decide which part to search
        if (target >= nums[0]) {
            return binarySearch(nums, 0, rotationIndex - 1, target);
        } else {
            return binarySearch(nums, rotationIndex, n - 1, target);
        }
    }
    
private:
    int findRotationIndex(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] > nums[i]) return i;
        }
        return 0;
    }
    
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    int n, target;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cin >> target;
    
    Solution solution;
    int result = solution.search(nums, target);
    
    cout << result << endl;
    
    return 0;
}

