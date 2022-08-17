class Solution {
public:
    
	// function to precompute if every substring of s is a palindrome or not
    vector<vector<bool>> isPalindrome(string& s){
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i=0; i<n; i++){
            dp[i][i] = true;
        }
        
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
            }
        }
        
        int k = 2;
        
        while(k < n){
            int i=0;
            int j=k;
            
            while(j<n){
                if(s[i] == s[j] and dp[i+1][j-1]){
                    dp[i][j] = true;
                }
                
                i++;
                j++;
            }
            
            k++;
        }
        
        return dp;
    }
    
	// function to find the minimum palindromic substrings in s
    int solve(string& s, int n, int i, vector<vector<bool>>& palin, vector<int>& memo){
        if(i==n){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        
        int result = INT_MAX;
        
        for(int j=i+1; j<=n; j++){
            if(palin[i][j-1]){
                result = min(result, 1+solve(s, n, j, palin, memo));
            }
        }
        
        return memo[i] = result;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> memo(n, -1);
        vector<vector<bool>> palin = isPalindrome(s);
        return solve(s, n, 0, palin, memo)-1;
    }
};
