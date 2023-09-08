// Runtime: 440 ms (Top 73.2%) | Memory: 70.79 MB (Top 29.5%)

class Solution 
{
    public int longestArithSeqLength(int[] nums) 
    {
        int n = nums.length;
        int longest = 0;
        Map<Integer, Integer>[] dp = new HashMap[n];
        
        for (int i = 0; i < n; i++) 
        {
            dp[i] = new HashMap<>();
            
            for (int j = 0; j < i; j++) 
            {
                int diff = nums[i] - nums[j];
                dp[i].put(diff, dp[j].getOrDefault(diff, 1) + 1);
                longest = Math.max(longest, dp[i].get(diff));
            }
        }
        
        return longest;
    }
}