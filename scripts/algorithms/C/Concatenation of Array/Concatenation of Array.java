// Runtime: 6 ms (Top 7.82%) | Memory: 50.1 MB (Top 50.44%)
class Solution {
    public int[] getConcatenation(int[] nums) {
        int[] ans = new int[2 * nums.length];
        for(int i = 0; i < nums.length; i++){
            ans[i] = ans[i + nums.length] = nums[i];
        }

        return ans;
    }
}