// Runtime: 2 ms (Top 16.64%) | Memory: 42.4 MB (Top 52.37%)

class Solution {
    public int findMiddleIndex(int[] nums) {

        for(int i=0;i<nums.length;i++)
        {
            int rsum=0;
            int lsum=0;

            for(int k=0;k<i;k++) lsum+=nums[k];
            for(int k=i+1;k<nums.length;k++) rsum+=nums[k];

            if(lsum==rsum){
                return i;
            }
        }

        return -1;

    }
}
