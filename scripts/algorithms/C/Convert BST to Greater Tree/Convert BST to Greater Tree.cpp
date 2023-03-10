class Solution {
public:
    int val = 0;
    TreeNode* convertBST(TreeNode* root) {

        if(root)
        {
            convertBST(root->right); // traverse right sub-tree
            val += root->val; // add val
            root->val = val; // update val
            convertBST(root->left); // traverse left sub-tree
        }
        
        return root;
    }
};