// Runtime: 305 ms (Top 34.88%) | Memory: 46.8 MB (Top 90.86%)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n, false), curr_vis(n, false), safe(n, true);

        for(int i=0; i<n; i++)
            if(!vis[i])
                dfs(i, vis, curr_vis, safe, graph);

        vector<int> ans;
        for(int i=0; i<n; i++)
            if(safe[i])
                ans.push_back(i);

        return ans;
    }

    bool dfs(int i, vector<bool> &vis, vector<bool> &curr_vis, vector<bool> &safe, vector<vector<int>>& graph){
        vis[i]=true, curr_vis[i]=true;

        for(auto j : graph[i]){
            if(!vis[j]){
                if(dfs(j, vis, curr_vis, safe, graph)==false)
                    return safe[i] = false;
            }
            else if(curr_vis[j])
                return safe[i] = false;
        }

        curr_vis[i]=false;
        return safe[i];
    }
};