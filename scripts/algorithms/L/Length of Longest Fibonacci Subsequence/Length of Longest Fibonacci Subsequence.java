class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        int dp[][] = new int[n][n];
        int res = 1;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0;i<n;i++){
            map.put(arr[i], i);
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                dp[i][j] = 2;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int sum = arr[i] + arr[j];
                if(map.containsKey(sum)){
                    int index = map.get(sum);
                    dp[j][index] = dp[i][j] + 1;
                }
                res = Math.max(dp[i][j], res);
            }
        }
        return res == 2?0:res;
    }
}