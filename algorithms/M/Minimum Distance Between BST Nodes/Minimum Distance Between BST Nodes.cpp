class Solution {
    int minDiff=INT_MAX,prev=INT_MAX;
public:
    void inorder(TreeNode* p){
        if(p==NULL) return;
        inorder(p->left);
        minDiff=min(minDiff,abs(p->val-prev));
        prev=p->val;
        inorder(p->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};