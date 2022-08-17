class Solution {
public:
    
    
    vector<vector<int>>dp;
    
    
    int recurs(vector<vector<int>>& cost,vector<int>&v,int i,int mask)
    {
        
        if(dp[i][mask]!=-1)
            return dp[i][mask];
        
        if(i<cost.size())
        {
            int res=INT_MAX;
            for(int j=0;j<cost[0].size();j++)
                res=min(res,recurs(cost,v,i+1,(mask|(1<<j)))+cost[i][j]);
            return dp[i][mask]=res;
        }
        else
        {
            int res=0;
            for(int  j=0;j<cost[0].size();j++)
                res+=v[j]*(!(mask&(1<<j)));
            return dp[i][mask]=res;   
        }
    }
    
    
    int connectTwoGroups(vector<vector<int>>& cost) {
        
        
        dp.resize(cost.size()+1,vector<int>(5000,-1));
        
        vector<int>v(cost[0].size(),0);
        
        for(int j=0;j<cost[0].size();j++)
        {
            int m=INT_MAX;
            for(int i=0;i<cost.size();i++)
                 m=min(m,cost[i][j]);
            v[j]=m;
        }
        
        
        return recurs(cost,v,0,0);
    }
};
