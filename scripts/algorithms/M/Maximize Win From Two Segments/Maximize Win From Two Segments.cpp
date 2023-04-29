class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> dp(n+1, 0);
        int res = 0;
        for (int start = 0, end = 0; end < n; end++){
            while (prizePositions[end] - prizePositions[start] > k){
                start++;
            }
            dp[end+1] = max(dp[end], end-start+1);
            res = max(res, end-start+1 + dp[start]);
        }
        return res;
    }
};