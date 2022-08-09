class Solution {
    public int maximumSum(int[] arr) {
        int n = arr.length;
        int[] prefixSum = new int[n+1];
        prefixSum[0] = 0;
        int ans = (int)-1e9;
        for(int i = 1; i <= n; i++){
            prefixSum[i] = prefixSum[i-1] + arr[i-1];
            ans = Math.max(ans, arr[i-1]);
        }
        if(ans < 0) return ans;  
        for(int i = 1; i <= n; i++){
            if(arr[i-1] < 0){
                int leftPrefixSum = 0;
                // find max in i to 0
                for(int j = i-1; j >= 0; j--){
                    leftPrefixSum = Math.max(leftPrefixSum, prefixSum[i-1] -prefixSum[j]);
                }
                
                int rightPrefixSum = 0;
                // find max in i to n
                for(int j = i+1; j <= n; j++){
                    rightPrefixSum = Math.max(rightPrefixSum, prefixSum[j] -prefixSum[i]);
                } 
                ans = Math.max(ans, leftPrefixSum + rightPrefixSum);
            }
        }
        return Math.max(ans, prefixSum[n]);
    }
}
