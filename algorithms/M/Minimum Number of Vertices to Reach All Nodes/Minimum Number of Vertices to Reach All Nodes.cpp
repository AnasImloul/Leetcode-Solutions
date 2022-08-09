class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>indegree(n+2),outdegree(n+2);
        for(auto i:edges)
        {
            indegree[i[1]]++;
            outdegree[i[0]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0 && outdegree[i]!=0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
