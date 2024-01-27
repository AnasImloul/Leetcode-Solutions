// Runtime: 13 ms (Top 100.0%) | Memory: 70.50 MB (Top 7.57%)

class Solution {
    public int matrixSum(int[][] nums) {
            int ans=0;
        for(int []row:nums)
        {
                Arrays.sort(row);
        }
            for(int i=0;i<nums[0].length;i++)
            {
                    int m=0;
                    for(int j=0;j<nums.length;j++)
                    {
                            if(m<nums[j][i])
                                    m=nums[j][i];
                    }
                    ans+=m;
            }
            return ans;
    }
}
