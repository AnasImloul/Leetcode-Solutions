
class Solution {
public:
    
    vector<vector<int>> ans;
    
    vector<vector<int>> levelOrder(Node* root) {
        
        dfs(root, 0);
        return ans;
    }
    
    void dfs(Node* root, int level) {
        
        if(!root) {
            return;
        }
        if(level == ans.size()) {
            ans.push_back({});
        }
        ans[level].push_back(root->val);
        for(auto i : root->children) {
            dfs(i, level+1);
        }
        
    }
    
};
