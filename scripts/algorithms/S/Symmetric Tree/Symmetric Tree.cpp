// Runtime: 3 ms (Top 94.24%) | Memory: 16.5 MB (Top 47.31%)
class Solution {
public:

    bool mirror(TreeNode* root1, TreeNode* root2){
        if(root1==NULL and root2==NULL) return true;
        if(root1==NULL or root2==NULL) return false;

        if(root1->val!=root2->val) return false;

        return mirror(root1->left, root2->right) and mirror(root1->right,root2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;

        return mirror(root->left,root->right);
    }
};