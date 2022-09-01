// Runtime: 7 ms (Top 27.34%) | Memory: 84.2 MB (Top 12.92%)
class Solution {
    public int getMaxLen(int[] nums)
    {
        int first_negative=-1;
        int zero_position=-1;
        int count_neg=0;
        int res=0;
        for(int i=0;i<nums.length;i++)
        {
            if (nums[i]<0)
            {
                count_neg = count_neg+1;
                if(first_negative==-1)
                {
                    first_negative=i;
                }
            }
            if (nums[i]==0)
            {
                count_neg = 0;
                zero_position=i;
                first_negative=-1;
            }
            else
            {
                if (count_neg%2==0)
                {
                    res=Math.max(i-zero_position,res);
                }
                else
                {
                    res=Math.max(i-first_negative,res);
                }
            }
        }
        return res;
    }
}