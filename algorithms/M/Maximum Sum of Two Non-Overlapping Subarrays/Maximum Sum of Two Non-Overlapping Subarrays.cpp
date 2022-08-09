class Solution {
public:
    
    int solve(vector<int>& prefixSum, int n, int firstLen, int secondLen){
        vector<int> dp(n, 0);
        
        dp[n-secondLen] = prefixSum[n]-prefixSum[n-secondLen];
        
        for(int i=n-secondLen-1; i>=0; i--){
            dp[i] = max(dp[i+1], prefixSum[i+secondLen]-prefixSum[i]);
        }
        
        dp[firstLen] = dp[firstLen] + prefixSum[firstLen]-prefixSum[0];
        
        for(int i=firstLen+1; i<=n-secondLen; i++){
            dp[i] = max(dp[i-1], dp[i] + (prefixSum[i]-prefixSum[i-firstLen]));
        }
        
        return *max_element(dp.begin(), dp.end());
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        
        for(int i=1; i<=n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        
        return max(solve(prefixSum, n, firstLen, secondLen), solve(prefixSum, n, secondLen, firstLen));
    }
};
