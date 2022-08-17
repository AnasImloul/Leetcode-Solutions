// two pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
              if (nums[left] != val) {
                 ++left;
              }
              else if (nums[right] == val) {
                 --right;
              }
              else if (left < right) {
                 nums[left++] = nums[right--];
              }
        }
        return left;
    }
};
