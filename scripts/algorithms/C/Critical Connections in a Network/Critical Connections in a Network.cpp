class Solution {
    int timer = 1;
public:
void dfs(vector<int>adj[] , int node , int parent , vector<int>&tin , vector<int>&low , vector<int>&vis , vector<vector<int>>&ans)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for(auto it:adj[node])
    {
        if(it == parent) continue;
        if(vis[it] == 0)
        {
            dfs(adj , it , node , tin , low , vis , ans);
            low[node] = min(low[node] , low[it]);
            if(tin[node] < low[it])
            ans.push_back({node , it});
        }
        else
        {
            low[node] = min(low[node] , low[it]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<int>adj[n];
        for(int i =  0;i<con.size();i++)
        {
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }
        vector<vector<int>>ans;
        vector<int>vis(n , 0) , tin(n , 0) , low(n , 0);
        dfs(adj ,  0 , -1 , tin , low , vis , ans);
        return ans;
    }
};