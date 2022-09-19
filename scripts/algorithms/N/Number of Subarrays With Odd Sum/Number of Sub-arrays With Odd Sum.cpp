// Runtime: 750 ms (Top 5.01%) | Memory: 191.6 MB (Top 5.00%)
class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int ind, int n, vector<int> &arr, int req, vector<vector<int>> &dp) {

        if(ind == n) return 0;
        if(dp[ind][req] != -1) return dp[ind][req];
        if(req == 1) {
            if(arr[ind] % 2 == 0) {
                return dp[ind][req] = solve(ind + 1, n, arr, req, dp);
            }
            else {
                return dp[ind][req] = (1 + solve(ind + 1, n, arr, !req, dp)) %mod;
            }
        }
        else {
            if(arr[ind] % 2 == 0) {
                return dp[ind][req] = (1 + solve(ind + 1, n, arr, req, dp)) %mod;
            }
            else {
                return dp[ind][req] = solve(ind + 1, n, arr, !req, dp);
            }
        }
    }
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        int count = 0;
        for(int i = 0; i < n; i++) {
            count = (count + solve(i, n, arr, 1, dp))% mod;
        }
        return count;
    }
};