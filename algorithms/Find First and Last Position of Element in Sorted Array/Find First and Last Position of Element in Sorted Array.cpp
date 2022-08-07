class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = FindBoundary(nums, target, true);
        int last = first == -1 ? -1 : FindBoundary(nums, target, false);
        return {first, last};
    }
    
private:
    int FindBoundary(const vector<int>& nums, int target, bool find_first) {
        int left = 0;
        int right = size(nums) - 1;
        int boundary_index = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                boundary_index = mid;
                if (find_first) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        
        return boundary_index;
    }
};
