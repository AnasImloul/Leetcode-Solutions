// Runtime: 67 ms (Top 52.83%) | Memory: 88.90 MB (Top 36.79%)

class Solution {
public:
    int minimumOperations(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n,1);
        int m=1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(v[i]>=v[j])
                {
                    dp[i]=max(dp[i],1+dp[j]);
                    m=max(m,dp[i]);
                }
            }
        }
        return n-m;
    }
};
