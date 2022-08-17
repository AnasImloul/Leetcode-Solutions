/* index shifted by 1 because when memoization applied negative index can't be passed as arg for function */
class Solution {
public:
    bool f(int i , int n ,int m, string &s1,string &s2,string &s3,vector<vector<int>> &dp){
        
        cout<<i<<n<<m<<endl;
        if(i==0) return true;
        if(n==0 && m ==0) return false;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        bool isMatchFoundS1 = false;
        if(n> 0 && s1[n-1] == s3[i-1])
            isMatchFoundS1 = f(i-1,n-1,m,s1,s2,s3,dp);
        
        bool isMatchFoundS2 = false;
        if(m >0 && s2[m-1] == s3[i-1])
            isMatchFoundS2 = f(i-1,n,m-1,s1,s2,s3,dp);
        
        return dp[n][m] = isMatchFoundS1 || isMatchFoundS2;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int b = s1.size();
        int c = s2.size();
        int a = s3.size();
        if(b + c != a) return false;
        
      vector<vector<int>> dp(b+1,vector<int>(c+1,-1));
       
        return f(a,b,c,s1,s2,s3,dp);
    }
};