class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        
        return 1+left+right;
    }
};
