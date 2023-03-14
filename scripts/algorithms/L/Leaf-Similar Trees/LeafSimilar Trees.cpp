class Solution {
public:
    void dfs(TreeNode* node, vector<int>& arr) {
        if (not node->left and not node->right) {
            arr.push_back(node->val);
            return;
        }
        if (node->left) dfs(node->left, arr);
        if (node->right) dfs(node->right, arr);
        return;
    }

    bool leafSimilar(TreeNode* a, TreeNode* b) {
        vector<int> aleaf, bleaf;
        dfs(a, aleaf);
        dfs(b, bleaf);
        return (aleaf == bleaf);
    }
};