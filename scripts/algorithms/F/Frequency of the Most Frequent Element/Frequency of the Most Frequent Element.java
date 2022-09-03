// Runtime: 46 ms (Top 33.83%) | Memory: 95.9 MB (Top 65.95%)
class Solution {
    public int maxFrequency(int[] nums, int k) {
        //Step-1: Sorting->
        Arrays.sort(nums);
        //Step-2: Two-Pointers->
        int L=0,R=0;
        long totalSum=0;
        int res=1;
        //Iterating over the array:
        while(R<nums.length)
        {
            totalSum+=nums[R];
            //The value of "totalSum+k" should be ">=" "windowSize*nums[R]"
            //then only the window is possible else decrease the "totalSum"
            //till the value "totalSum+k" is ">=" "windowSize*nums[R]"
            while(! ((totalSum+k) >= ((R-L+1)*nums[R])) )
            {
                totalSum-=nums[L];
                L++;
            }
            res=Math.max(res,(R-L+1));
            R++;
        }
        return res;
    }
}