class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        vector<int>ans(k,0);
        unordered_map<int,unordered_set<int>>m;

        for(int i = 0; i<logs.size(); i++)
        {
            m[logs[i][0]].insert(logs[i][1]);
        }
        for(auto x : m)
        {
            int t = x.second.size();
            ans[t-1]++;
        }
        return ans;
    }
};