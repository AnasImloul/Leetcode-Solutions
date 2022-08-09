class Solution {
    public int waysToSplit(int[] nums) {
        int size = nums.length;
        for (int i = 1; i < size; ++i) {
            nums[i] += nums[i - 1];
        }
        int res = 0;
        int mod = 1_000_000_007;
        for (int i = 0; i < size - 2; ++i) {
            int left = searchLeft(nums, i, size - 1);
            int right = searchRight(nums, i, size - 1);
            if (left == -1 || right == -1) {
                continue;
            }
            res = (res + right - left + 1) % mod;
        }
        return res;
    }
    
    private int searchLeft(int[] nums, int left, int right) {
        int pos = -1;
        int min = nums[left];
        int lo = left + 1, hi = right - 1;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            int mid = nums[mi] - min;
            int max = nums[right] - nums[mi];
            if (mid < min) {
                lo = mi + 1;
            } else if (max < mid){
                hi = mi - 1;
            } else {
                pos = mi;
                hi = mi - 1;
            }
        }
        return pos;
    }
    
    private int searchRight(int[] nums, int left, int right) {
        int pos = -1;
        int min = nums[left];
        int lo = left + 1, hi = right - 1;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            int mid = nums[mi] - min;
            int max = nums[right] - nums[mi];
            if (mid < min) {
                lo = mi + 1;
            } else if (max < mid){
                hi = mi - 1;
            } else {
                pos = mi;
                lo = mi + 1;
            }
        }
        return pos;
    }
    
}
