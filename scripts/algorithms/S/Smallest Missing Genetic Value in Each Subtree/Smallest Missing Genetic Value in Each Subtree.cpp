// Runtime: 896 ms (Top 26.83%) | Memory: 168.9 MB (Top 55.75%)

class Solution {
public:
    unordered_set<int> visited;
    vector<int> nums ;
    vector<vector<int>> adj;

    void dfs(int node){
        for(auto child:adj[node]){
            if(!visited.count(nums[child])){
                visited.insert(nums[child]);
                dfs(child);
            }
        }
    }

    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size(), missing = 1;
        adj.resize(n);
        vector<int> res;
        this->nums = nums;
        res.resize(n,1);

        for(int i=1; i<n; i++) adj[parents[i]].push_back(i);

        int node = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == 1) {
                node = i;
                break ;
            }
        }
        if(node == -1) return res;
        while(node != -1) {
            visited.insert(nums[node]);
            dfs(node);
            while(visited.count(missing)) missing++;
            res[node] = missing;
            node = parents[node];
        }
        return res;
    }
};