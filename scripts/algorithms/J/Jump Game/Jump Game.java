// Runtime: 3 ms (Top 67.02%) | Memory: 67.1 MB (Top 78.50%)
class Solution {
    public boolean canJump(int[] nums)
    {
        int maxjump = 0;
        for(int i=0;i<nums.length;i++)
        {
            // If the current index 'i' is less than current maximum jump 'curr'. It means there is no way to jump to current index...
            // so we should return false
            if(maxjump<i)
                return false;
            else
                maxjump = Math.max(maxjump,nums[i]+i); // Update the current maximum jump...
        }
        return true;
    }
}

//nums[i]+1 gives themax jump index possible from i