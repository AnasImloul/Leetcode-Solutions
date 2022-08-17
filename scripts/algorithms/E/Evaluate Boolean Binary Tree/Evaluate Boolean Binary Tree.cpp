class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        
        if (!root->left and !root->right)   return root->val;
        int l = evaluateTree(root->left);
        int r = evaluateTree(root->right);
        return (root->val == 2) ? l or r : l and r;
    }
};
