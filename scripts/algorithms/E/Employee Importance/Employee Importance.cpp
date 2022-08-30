// Runtime: 82 ms (Top 10.64%) | Memory: 15.7 MB (Top 29.77%)
class Solution {
public:
    int ans=0;
    void helper(unordered_map<int,pair<int,vector<int>>> &res,int id,vector<int> &dp)
    {
        if(dp[id]==-1)
        {ans+=res[id].first;dp[id]=1;}// employees[id-1]->importance;dp[id-1]=1;}
        else return;
        for(int i=0;i<res[id].second.size();i++)
            helper(res,res[id].second[i],dp);
    }
    int getImportance(vector<Employee*> employees, int id) {
        vector<int> dp(2001,-1);
        unordered_map<int,pair<int,vector<int>>> res;
        for(int i=0;i<employees.size();i++)
            res[employees[i]->id]={employees[i]->importance,employees[i]->subordinates};
        helper(res,id,dp);
        return ans;
    }
};