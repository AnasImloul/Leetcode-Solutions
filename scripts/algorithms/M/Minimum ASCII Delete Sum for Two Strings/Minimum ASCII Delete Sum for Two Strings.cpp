class Solution {
public:
   long long int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp)
    {
        if(i<0) {
            long long ans=0;
           for(int k=0;k<j+1;k++)
           {
              int x=int(t[k]);
              ans+=x;
           }
           return ans;
        }
        if(j<0)
        { 
            long long ans=0;
           for(int k=0;k<i+1;k++)
           {
              int x=int(s[k]);
              ans+=x;
           }
           return ans;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]= solve(i-1,j-1,s,t,dp);
        else{
           long long x=int(s[i]) +solve(i-1,j,s,t,dp);
             long long y=int(t[j])+solve(i,j-1,s,t,dp);
             return dp[i][j]=min(x,y);
        }
    }
    long long int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,s1,s2,dp);
    }
};