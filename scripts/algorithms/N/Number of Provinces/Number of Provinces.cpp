// Runtime: 51 ms (Top 25.06%) | Memory: 13.8 MB (Top 67.00%)
class Solution {
private:
    void dfs(int node,vector<vector<int>> &graph,int n,vector<bool> &vis){

        vis[node] = true;

        for(int j = 0; j < graph[node].size(); j++){
            if(graph[node][j] == 1 and !vis[j]){
                dfs(j,graph,n,vis);
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<bool> vis(n,false);

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans++;
                dfs(i,isConnected,n,vis);
            }
        }

        return ans;

    }
};