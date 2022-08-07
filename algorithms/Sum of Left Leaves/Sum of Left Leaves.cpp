class Solution {
    int sum=0;
public:
    bool solve(TreeNode* root){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL) return true;
        if(solve(root->left)) sum+=root->left->val;
        solve(root->right);
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root);
        return sum;
    }
};