// Runtime: 0 ms (Top 100.00%) | Memory: 43.6 MB (Top 61.18%)
class Solution {
    public int findMin(int[] nums) {
        int l = 0;
        int h = nums.length - 1;
        while (l < h) {
            while (l < h && nums[l] == nums[l + 1])
                ++l;
            while (l < h && nums[h] == nums[h - 1])
                --h;
            int mid = l + (h - l) / 2;
            if (nums[mid] > nums[h]) { // smaller elements are in the right side
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return nums[l];
    }
}