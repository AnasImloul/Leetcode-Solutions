// Runtime: 11 ms (Top 85.53%) | Memory: 42.5 MB (Top 53.95%)
class Solution {
    public int minDistance(int[] houses, int k) {
        Arrays.sort(houses);
        int n = houses.length;
        int[] dp = new int[n];
        for (int i = 1; i < n; i++){ // know optimal dist for i-1, then for i, we add houses[i] - houses[i/2]
            dp[i]=dp[i-1]+houses[i]-houses[i/2];
        }
        for (int i = 0; i < k-1; i++){
            int[] next = new int[n];
            Arrays.fill(next, Integer.MAX_VALUE);
            for (int j = 0; j < n; j++){
                int sum = 0;
                for (int m = j; m >= 0; m--){
                    sum += houses[(m+j+1)>>1]-houses[m]; // likewise, adding to the front needs the +1 to account for the truncation.
                    next[j] = Math.min(next[j], (m==0?0:dp[m-1])+sum);
                }
            }
            dp=next;
        }
        return dp[n-1];
    }
}