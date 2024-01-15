// Runtime: 2 ms (Top 100.0%) | Memory: 61.40 MB (Top 26.22%)

class Solution {
    public long countSubarrays(int[] nums, long k) {
        int i=0;
        int  j=0;
        long max = 0;
        long operation = 0;

        while(j < nums.length){
            operation += nums[j];
            while(operation*(j-i+1) >= k){
                operation -= nums[i];
                i++;
            }
            max += j-i+1;
            j++;
        }
        return max;

    }
}
