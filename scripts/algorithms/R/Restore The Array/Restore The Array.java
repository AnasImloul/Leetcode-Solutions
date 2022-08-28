// Runtime: 126 ms (Top 51.52%) | Memory: 71.7 MB (Top 43.43%)
class Solution {
    static long mod;
    private long solve(int idx,String s,int k,long[] dp){
        if(idx==s.length())
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        long max=0,number=0;
        for(int i=idx;i<s.length();i++){
            int temp=s.charAt(i)-'0';
            number=(number*10)+temp;
            if(number>=1 && number<=k){
                max=(max+solve(i+1,s,k,dp))%mod;
            }else
                break;
        }
        return dp[idx]=max;
    }
    public int numberOfArrays(String s, int k) {
        mod = (int)1e9+7;
        long[] dp=new long[s.length()+1];
        Arrays.fill(dp,-1);
        return (int)solve(0,s,k,dp);
    }
}