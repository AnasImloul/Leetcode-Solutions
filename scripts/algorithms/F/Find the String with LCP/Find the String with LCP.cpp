// Runtime: 197 ms (Top 74.42%) | Memory: 81.00 MB (Top 25.58%)

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string res(n,'a');
        res[0]='a';     
        char mn='b';
        for(int i=1;i<n;i++)
        {
            bool set=false;
            for(int j=0;j<i;j++){
                if(lcp[i][j]!=0){
                    set=true;
                    res[i]=res[j];
                    break;
                }
            }
            if(!set)    res[i]=mn++;
        }
        for(int i=0;i<n;i++)    if(res[i]>'z')  return "";
        vector<vector<int>> dp(n,vector<int>(n,0));     // suffix count

        for(int i=n-1;i>=0;i--)
            for(int j=n-1;j>=0;j--)
                if(res[i]==res[j])  dp[i][j]=1+((i<n-1 && j<n-1)?dp[i+1][j+1]:0);
        
        for(int i=0;i<n;i++)        // now my 2 arrays should be equal
            for(int j=0;j<n;j++)
                if(dp[i][j]!=lcp[i][j]) return "";
        
        
        return res;
    }
};
