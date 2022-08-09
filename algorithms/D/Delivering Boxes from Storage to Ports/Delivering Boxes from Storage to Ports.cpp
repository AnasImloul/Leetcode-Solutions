class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size(); 
        vector<int> dp(n+1, INT_MAX); 
        dp[0] = 0; 
        
        int trips = 2; 
        for (int i = 0, ii = 0; i < n; ++i) {
            maxWeight -= boxes[i][1]; 
            if (i && boxes[i-1][0] != boxes[i][0]) ++trips; 
            for (; maxBoxes < i - ii + 1 || maxWeight < 0 || (ii < i && dp[ii] == dp[ii+1]); ++ii) {
                maxWeight += boxes[ii][1]; 
                if (boxes[ii][0] != boxes[ii+1][0]) --trips; 
            }
            dp[i+1] = dp[ii] + trips; 
        }
        return dp.back(); 
    }
};
