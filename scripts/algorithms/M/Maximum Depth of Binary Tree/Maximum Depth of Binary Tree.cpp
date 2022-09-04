// Runtime: 4 ms (Top 96.96%) | Memory: 18.9 MB (Top 14.27%)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};