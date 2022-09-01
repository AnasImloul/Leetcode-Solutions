// Runtime: 22 ms (Top 94.19%) | Memory: 42.1 MB (Top 89.53%)
class Solution {
    public int numberWays(List<List<Integer>> hats) {
        int n = hats.size(), M = (int)1e9+7;
        int[] mask = new int[41];
        for (int i = 0; i < n; i++){
            for (int h : hats.get(i)){
                mask[h]|=1<<i;
            }
        }
        int[] dp = new int[1<<n];
        dp[0]=1;
        for (int i = 0; i <= 40; i++){
            for (int j = (1<<n)-1; j >= 0 && mask[i]>0; j--){
                for (int k = 0; k < n && (mask[i]&j)>0; k++){
                    if ((1<<k&j)>0 && (1<<k&mask[i])>0){
                        dp[j]+=dp[j^1<<k];
                        dp[j]%=M;
                    }
                }
            }
        }

        return dp[(1<<n)-1];
    }
}