// Runtime: 23 ms (Top 59.57%) | Memory: 14.3 MB (Top 23.43%)
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
        {
            return NULL;
        }
        if(root==p or root == q)
        {
            return root;
        }
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        if(left and right) return root;
        if(left) return left;
        else return right;

    }
};