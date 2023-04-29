class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        
        int least = min (m,n);
        
        vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
        
        /*
        create dp matrix with sum of all squares
        so for the following input matrix
         1 1 1 1
         1 0 0 0
         1 0 0 0
         1 0 0 0
         
        m = 4; n = 4; least = 4; threshold = 6
        you get the dp matrix to be:
         0 0 0 0 0
         0 1 2 3 4
         0 2 3 4 5
         0 3 4 5 6
         0 4 5 6 7
        */
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i+1][j+1] = mat[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i][j];
            }
        }
        
        int sum = 0;
        
        /*
        from the previous example the once we start looking from least = 4 to see if the sum is less than threshold
        for least = 4; sum = 7 - 0 - 0 + 0. (looking at the full 4 x 4 matrix) 7 is > threshold.. so keep looking..
        for least = 3; sum = 5 - 0 - 0 + 0. (looking at the 3 x 3 matrix) .. 5 < threshold.. return 3.
        
        say if the threshold was lower e.g. threshold = 2?
        continuing...
        for least = 3; sum = 6 - 3 - 0 + 0 = 3.
        for least = 3; sum = 6 - 0 - 3 + 0 = 3;
        for least = 3; sum = 7 - 4 - 4 + 1 = 0;
        
        */
        
        for(int k = least; k > 0; k--) {
            for(int i = k; i < m+1; i++) {
                for(int j = k; j < n+1; j++) {
                    sum = dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k];
                    if(sum <= threshold) {
                        return k;
                    }
                }
            }
        }
        
        return 0;
    }
};