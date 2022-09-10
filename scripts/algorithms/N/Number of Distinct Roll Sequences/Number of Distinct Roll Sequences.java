// Runtime: 361 ms (Top 36.73%) | Memory: 68 MB (Top 53.88%)
class Solution {
    static long[][] dp;
    public int distinctSequences(int n) {
        if(n==1) return 6;
        int mod = 1_000_000_007;
        dp =new long[][]
                {
                    {0,1,1,1,1,1},
                    {1,0,1,0,1,0},
                    {1,1,0,1,1,0},
                    {1,0,1,0,1,0},
                    {1,1,1,1,0,1},
                    {1,0,0,0,1,0}
                };
        for(int i=2;i<n;i++){
            long[][] temp = new long[6][6];
            for(int j=0;j<6;j++){
                for(int k=0;k<6;k++){
                    long total = 0;
                    if(dp[j][k] == 0) continue;
                    for(int l=0;l<6;l++){
                        total = (total + ((l==k)?0:dp[l][j]))%mod;
                    }
                    temp[j][k] = total;
                }
            }
            dp = temp;
        }
        long result = 0;
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                result = (result + dp[i][j])%mod;
            }
        }
        return (int)(result);
    }
}