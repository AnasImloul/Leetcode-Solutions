class Solution {
    public int minCost(int n, int[] cuts) {
        
        int len = cuts.length;
        
        Arrays.sort(cuts);
        
        int[] arr = new int[len+2];
        for(int i = 1 ; i <= len ; i++)
            arr[i] = cuts[i-1];
        
        arr[0] = 0;
        arr[len+1] = n;
        int[][] dp = new int[len+1][len+1];
        for(int i = 0 ; i <= len ; i++)
            for(int j = 0 ; j <= len ; j++)
                dp[i][j] = -1;
        return cut(arr , 1 , len , dp);
    }
    
    int cut(int[] cuts , int i , int j , int[][] dp){
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mini = Integer.MAX_VALUE;
        for(int k = i ; k <= j ; k++){
            int cost = cuts[j+1]-cuts[i-1] + cut(cuts , i , k-1 , dp) + cut(cuts , k+1 , j , dp);
            mini = Math.min(cost , mini);
        }
        
        return dp[i][j] = mini;
    }
}
