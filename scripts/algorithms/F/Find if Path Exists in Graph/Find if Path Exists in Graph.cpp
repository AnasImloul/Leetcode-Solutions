// Runtime: 1891 ms (Top 5.09%) | Memory: 280.7 MB (Top 5.05%)
class Solution {
private:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> visited;

    bool dfs(int node, int destination){
        visited[node] = true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                if(neighbour == destination)
                    return true;
                if(dfs(neighbour, destination))
                    return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;

        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(source, destination);
    }
};