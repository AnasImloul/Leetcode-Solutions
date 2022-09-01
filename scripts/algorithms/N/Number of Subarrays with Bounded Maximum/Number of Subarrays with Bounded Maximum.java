// Runtime: 4 ms (Top 82.54%) | Memory: 72.1 MB (Top 7.10%)
class Solution {
    public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        int res = 0;

        int s = -1;
        int e = -1;

        for(int i=0;i<nums.length;i++){

            if(nums[i] >= left && nums[i] <= right){
                e = i;
            }else if(nums[i] > right){
                e = s = i;
            }

            res += (e - s);
        }

        return res;
    }
}