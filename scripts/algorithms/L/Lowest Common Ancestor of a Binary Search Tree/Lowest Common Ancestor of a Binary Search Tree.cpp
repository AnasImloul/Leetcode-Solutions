// Runtime: 47 ms (Top 42.80%) | Memory: 23.4 MB (Top 13.91%)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<root->val && q->val<root->val) return lowestCommonAncestor(root->left,p,q);
        else if(p->val>root->val && q->val>root->val) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};