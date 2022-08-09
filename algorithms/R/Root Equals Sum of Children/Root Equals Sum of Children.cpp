class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root->left->val+root->right->val==root->val){
            return true;
        }
        return false;
    }
};
