// Runtime: 0 ms (Top 100.0%) | Memory: 43.60 MB (Top 22.49%)

class Solution {
    public int minMaxGame(int[] nums) {
        int len=nums.length;
        if(len==1)
            return nums[0];
        int[] newNums=new int[len/2];
        int index=0;
        for(int i=0;i<len;i+=2)
        {
            if(index%2==0)
            {
                newNums[index++]=Math.min(nums[i],nums[i+1]);
            }
            else
            {
                newNums[index++]=Math.max(nums[i],nums[i+1]);
            }
        }
        return minMaxGame(newNums);
    }
}
