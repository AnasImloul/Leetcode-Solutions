// Runtime: 1 ms (Top 71.82%) | Memory: 41.2 MB (Top 34.16%)
class Solution {
    public int getMaximumGenerated(int n) {
        if(n==0 || n==1) return n;

        int nums[]=new int [n+1];

        nums[0]=0;
        nums[1]=1;
        int max=Integer.MIN_VALUE;

        for(int i=2;i<=n;i++){
            if(i%2==0){
                nums[i]=nums[i/2];
            }
            else{
                nums[i]=nums[i/2]+nums[i/2 + 1];
            }
            max=Math.max(max,nums[i]);
        }
        return max;
    }
}