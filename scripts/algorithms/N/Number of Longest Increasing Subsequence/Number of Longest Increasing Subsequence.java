// Runtime: 29 ms (Top 72.27%) | Memory: 44.7 MB (Top 20.08%)
class Solution {
    public int findNumberOfLIS(int[] nums) {
        int N = nums.length;
        int []dp =new int[N];
        int []count = new int[N];
        Arrays.fill(dp,1);Arrays.fill(count,1);
        int maxi = 1;
        for(int i=0;i<N;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    //inherit a new one
                    count[i]=count[j];
                    maxi = Math.max(dp[i],maxi);
                }else if(nums[j] < nums[i] && dp[j]+1 == dp[i]){
                    //got one as same len, increase count
                    count[i]+=count[j];
                }
            }
        }//for ends
        int maxlis=0;
        for(int i=0;i<N;i++){
            if(maxi == dp[i]){
                maxlis+=count[i];
            }
        }
        return maxlis;
    }
}