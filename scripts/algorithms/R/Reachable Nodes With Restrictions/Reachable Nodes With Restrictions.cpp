class Solution {
public:
    int dfs(vector<int>adj[],int uu,vector<int>&res,vector <int>&vis){
        vis[uu]=1;
        int count=1;
        for(auto nn:adj[uu]){
            if(res[nn]==1){
                continue;
            }
            
            if(vis[nn]==-1){
                count+=dfs(adj,nn,res,vis);
            }
        }
        return count;
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector <int> adj[n];
        vector <int> vis(n,-1);
   
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector <int> res(n,0);
        for(int i=0;i<restricted.size();i++){
            res[restricted[i]]=1;
        }
        return dfs(adj,0,res,vis);
    }
};
