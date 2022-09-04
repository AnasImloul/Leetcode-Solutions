// Runtime: 24 ms (Top 10.87%) | Memory: 165.8 MB (Top 61.96%)
class Solution
{
    public int[] getAverages(int[] nums, int k)
    {
        if(k == 0)
            return nums;

        int N = nums.length;
        long[] sum = new long[N];
        sum[0] = nums[0];

        for(int i = 1; i < N; i++)
            sum[i] = sum[i-1]+nums[i]; // Sum of 0 - ith element at sum[i]

        int[] ret = new int[N];
        Arrays.fill(ret,-1);

        for(int i = k; i < N-k; i++) // Beyond this range, there are less than k elements so -1
        {
            long temp = (sum[i+k]-sum[i-k]+nums[i-k])/(k*2+1);
            ret[i] = (int)temp;
        }
        return ret;
    }
}