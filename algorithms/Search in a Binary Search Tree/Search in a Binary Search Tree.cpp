// Recursive
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int& val) {
        if(root==NULL) return NULL;
        if(root->val==val) return root;
        if(root->val>val) return searchBST(root->left,val);
        return searchBST(root->right,val);
    }
};

// Iterative
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val==val) return root;
            root=root->val>val?root->left:root->right;
        }
        return NULL;
    }
};