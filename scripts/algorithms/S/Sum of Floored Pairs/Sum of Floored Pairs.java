class Solution {
    public int sumOfFlooredPairs(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        long cnt[]=new long[nums[n-1]+2];
        for(int num:nums){
            cnt[num+1]++;
        }
        for(int i=1;i<cnt.length;i++){
            cnt[i]+=cnt[i-1];
        }
        long res=0;
        long mod=1000000007;
        long dp[]=new long[cnt.length];
        for(int num:nums){
            if(dp[num]!=0){
                res=(res+dp[num])%mod;
                continue;
            }
            long tot=0;
            for(int j=num;j<cnt.length-1;j+=num){
                tot=(tot+(j/num)*(cnt[Math.min(j+num-1,nums[n-1])+1]-cnt[j]))%mod;
            }
            dp[num]=tot;
            res=(res+tot)%mod;
        }
        return (int)res;
    }
}
