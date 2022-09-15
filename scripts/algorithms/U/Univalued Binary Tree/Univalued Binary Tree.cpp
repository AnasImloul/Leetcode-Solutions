// Runtime: 8 ms (Top 19.98%) | Memory: 9.9 MB (Top 77.87%)
class Solution {
public:
    bool recur(TreeNode* root, int value){
        if(root==NULL)
            return true;
        if(root->val!=value){
            return false;
        }
        return recur(root->left,value) &&recur(root->right,value);

    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
            return true;
        int value=root->val;
        return recur(root,value);

    }
};
