class Solution {
public:
    
    int s = 0;
    
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->right);
        
        root->val = s + root->val;
        s = root->val;
        
        solve(root->left);
        return;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL;
        solve(root);
        return root;
    }
};
