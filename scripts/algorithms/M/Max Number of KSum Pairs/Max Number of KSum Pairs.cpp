// Runtime: 97 ms (Top 81.13%) | Memory: 58.50 MB (Top 58.54%)

class Solution {
public: // Time/Space: O(nlogn); O(1)
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right && nums[left] < k) {  // pruning:  nums[left] < k
            if (nums[left] + nums[right] < k) {
                left++;
            } else if (nums[left] + nums[right] > k) {
                right--;
            } else {
                left++;
                right--;
                count++;
            }
        }
        return count;
    }
};
