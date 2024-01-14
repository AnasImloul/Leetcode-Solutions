// Runtime: 2 ms (Top 92.18%) | Memory: 45.00 MB (Top 17.26%)

class Solution
{
    public int findClosestNumber(int[] nums)
    {
        int res = Integer.MAX_VALUE;
        for(int i: nums)
            if(Math.abs(i) < Math.abs(res) || i == Math.abs(res))
                res = i;
        return res;
    }
}
