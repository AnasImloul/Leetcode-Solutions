// Runtime: 1 ms (Top 97.73%) | Memory: 44.9 MB (Top 43.86%)
class Solution {
    public int maxProduct(int[] nums) {
        int ans = Integer.MIN_VALUE;
        int m = 1;
        for(int i=0; i< nums.length; i++){
            m*=nums[i];
            ans = Math.max(m, ans);
            if(m == 0) m=1;
        }
        int n = 1;
        for(int i=nums.length-1; i>=0; i--){
            n*=nums[i];
            ans = Math.max(n, ans);
            if(n == 0) n=1;
        }
        return ans;
    }
}