class Solution {
public:
    int count=1;  // node 0 is already reached as it is starting point
    vector<vector<int>> graph;
    unordered_set<int> res;  // to store restricted numbers for fast fetch
    vector<bool> vis;  // visited array for DFS
    
    void dfs(int i){
        for(int y: graph[i]){
            if(!vis[y] && res.count(y)==0){
                vis[y]= true;
                dfs(y);
                count++;
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for(int x:restricted) res.insert(x);
        
        // creating graph
        graph.resize(n);
        vis.resize(n);
        for(auto &x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        // mark 0 as visited coz it is starting point and is already reached 
        vis[0]= true;
        dfs(0);
        
        return count;
    }
};