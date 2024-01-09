// Runtime: 12 ms (Top 56.49%) | Memory: 15.30 MB (Top 39.4%)

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        return (root->val < 2) ? root->val : (root->val == 2) ? evaluateTree(root->left) || evaluateTree(root->right) : evaluateTree(root->left) && evaluateTree(root->right);
    }
};
