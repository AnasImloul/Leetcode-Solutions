// Runtime: 20 ms (Top 78.88%) | Memory: 8 MB (Top 44.62%)
class Solution {
public:
    double solve(vector<int>&nums, int index, int k, vector<vector<double>>&dp){
        if(index<0)
            return 0;
        if(k<=0)
            return -1e8;

        if(dp[index][k]!=-1)
            return dp[index][k];

        double s_sum = 0;
        double maxi = INT_MIN;
        int cnt = 1;
        for(int i=index;i>=0;i--){
            s_sum += nums[i];
            maxi = max(maxi, (s_sum/cnt) + solve(nums, i-1, k-1, dp));
            cnt++;
        }
        return dp[index][k] = maxi;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>>dp(n, vector<double>(k+1, -1));
        return solve(nums, n-1, k, dp);
    }
};