class Solution {
    boolean isPos(int nums[],long target){
        long arr[] = new long[nums.length];
        for(int i = 0;i < nums.length;i++) arr[i] = (long)nums[i];
        for(int i = 0;i < arr.length - 1;i++){
            if(arr[i] > target) return false;
            arr[i + 1] -= (target - arr[i]);
        }
        return arr[arr.length - 1] <= target;
    }
    public int minimizeArrayValue(int[] nums) {
        long l = 0,h = (long)1e9;
        long ans = l;
        for(;l <= h;){
            long mid = (l + h) >> 1;
            if(isPos(nums,mid)){
                h = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        return (int)ans;
    }
}