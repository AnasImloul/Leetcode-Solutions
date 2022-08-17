/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void convert(TreeNode* &root,int& n){
        if(!root){
            return ;
        }
        convert(root->right,n);
        n += root->val;
        root->val = n;
        convert(root->left,n);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root){
            return NULL;
        }
        int num = 0;
        convert(root,num);
        return root;
    }
};
