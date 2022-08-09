class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(j >= t.size()) return 1;
        if(i >= s.size() || t.size() - j > s.size() - i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        for(int k = i; k < s.size(); k++){
            if(s[k] == t[j]) res += solve(s, t, k+1, j+1, dp); 
        }
        return dp[i][j] = res;
    }
    
    int numDistinct(string s, string t) {
        if(s.size() == t.size()) return s == t;
        vector<vector<int>> dp(s.size(), vector<int> (t.size(), -1));
        return solve(s, t, 0 , 0, dp);
    }
};
