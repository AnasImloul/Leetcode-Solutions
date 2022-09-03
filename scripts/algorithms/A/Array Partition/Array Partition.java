// Runtime: 21 ms (Top 17.21%) | Memory: 54.6 MB (Top 23.48%)
class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        for(int i = 0; i < nums.length; i+=2){
            sum += nums[i];
        }
        return sum;
    }
}