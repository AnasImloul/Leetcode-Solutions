// Runtime: 2012 ms (Top 5.03%) | Memory: 15.9 MB (Top 37.78%)
class Solution {
public:

    int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){

        //to handle edge cases if the j index is less than 0 or greater than size of the array.
        if(j<0 or j>=matrix[0].size()) return 1e8;

        //base case
        if(i==0) return dp[0][j] = matrix[0][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = INT_MAX;

         //Here we have to iterate through all the possiblities in the entire upper row for each
         //element except for the element which is directly above the current element in the
         //matrix, and then we have to find the minimum.
        for(int k=0;k<matrix[0].size();k++){
            if(k==j) continue;
            ans = min(ans, matrix[i][j] + f(i-1, k, matrix, dp));
        }

        return dp[i][j] = ans;

    }

    int minFallingPathSum(vector<vector<int>>& grid) {

        int mini = INT_MAX;
        int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n,-1));

        for(int j=0;j<n;j++){

            mini = min(mini, f(n-1, j, grid, dp));

        }

        return mini;

    }
};