class Solution {
public:
    void dfs(vector<vector<int>> &graph,int i,int j,vector<vector<int>> &ans,vector<bool> &vis){
        vis[j]=true;
        for(auto &x:graph[j]){
            if(!vis[x]){
                ans[x].push_back(i);
                dfs(graph,i,x,ans,vis);
            }
            
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> ans(n),graph(n);
        for(auto &v:edges){
            graph[v[0]].push_back(v[1]);
        }
        for(int i=0;i<n;i++){
            vector<bool> vis(n);
            dfs(graph,i,i,ans,vis);
        }
        return ans;
    }
};
