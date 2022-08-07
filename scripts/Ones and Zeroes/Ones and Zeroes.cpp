class Solution {
public:
    int dp[102][102][601];
    int countzero(string s)
    {   int c=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0') c++;
        }
        return c;
    }
    int solve(vector<string>&strs, int index, int m, int n,int ans)
    {
        if(index==strs.size() )
        {
            return ans;
            //return 0;
        }
        
        int c0= countzero(strs[index]);
        int c1= strs[index].size()-c0;
        
        if(dp[m][n][index]!=-1) return dp[m][n][index];
        
        int a=INT_MIN, b=INT_MIN;
        
        if(m-c0>=0 && n-c1>=0)
        {
           // int c=ans;
            a= solve(strs, index+1, m-c0, n-c1,ans+1);
            
            
        }
        b=solve(strs, index+1, m, n,ans);
        return  dp[m][n][index]=max(a,b);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp, -1,sizeof(dp));
        
        return solve(strs, 0, m , n,0 ) ;
    }
};
