// Runtime: 397 ms (Top 87.55%) | Memory: 168.60 MB (Top 83.82%)

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<int> adj[n];
        
        // A visited array.
        vector<int> vis(n,0);
        
        // Count varable to keep count of traversed nodes.
        int cnt = 0;
        
        // Mark all restricted node as visited.
        for(int i=0;i<restricted.size();i++)
            vis[restricted[i]] = 1;
        
        // Make adjency list.
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        // Perform normal DFS starting from 0th node.
        dfs(adj, vis, 0, cnt);
        
        return cnt;
        
    }
    
    
    void dfs(vector<int> adj[], vector<int> &vis, int node, int &cnt)
    {
        vis[node] = 1;
        cnt++;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
                dfs(adj, vis, it, cnt);
        }
    }
    
};
