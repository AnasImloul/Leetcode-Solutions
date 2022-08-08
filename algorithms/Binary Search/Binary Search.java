class Solution {
    public int search(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        return binarySearch(nums, l, r, target);
    }
    
    private int binarySearch(int[] nums, int l, int r, int target) {
        if (l <= r) {
            int mid = (r + l) / 2;
        
            if (nums[mid] == target) {
                return mid;
            } 
        
            if (nums[mid] < target) {
                return binarySearch(nums, mid + 1, r, target);
            } else {
                return binarySearch(nums, l, mid - 1, target);
            }
        } 
        return -1;
    }
}
