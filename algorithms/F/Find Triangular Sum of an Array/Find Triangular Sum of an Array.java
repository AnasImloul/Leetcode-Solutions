class Solution {
    public int triangularSum(int[] nums) {
        while(nums.length > 1){
            int[] arr = new int[nums.length-1];
            for(int i=0; i<arr.length; i++){
                arr[i] = (nums[i] + nums[i+1]) % 10;
            }
            nums = arr;
        }
        return nums[0];
    }
}
