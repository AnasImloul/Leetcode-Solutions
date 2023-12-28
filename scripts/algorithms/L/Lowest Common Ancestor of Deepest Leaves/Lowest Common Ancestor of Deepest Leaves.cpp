// Runtime: 24 ms (Top 5.16%) | Memory: 21.30 MB (Top 86.33%)

class Solution {
public:
    int getDepth(TreeNode* root) {
        if (!root)
            return 0;
        return max(getDepth(root->right), getDepth(root->left)) + 1;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
            return NULL;
        
        int right_depth = getDepth(root->right);
        int left_depth = getDepth(root->left);
        
        if (right_depth == left_depth)
            return root;
        
        if (right_depth > left_depth) 
            return lcaDeepestLeaves(root->right);
        
        else 
            return lcaDeepestLeaves(root->left);
    }
};
