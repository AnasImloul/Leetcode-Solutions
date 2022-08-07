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
public:
    void fixBST(TreeNode* root, TreeNode* & prev ,TreeNode* & first ,TreeNode* &second){
        if(root == NULL){
            return ;
        }
//         inorder traversal
        fixBST(root->left ,prev,first,second);
       
        if(prev != NULL and prev->val > root->val){
//             this is violtaing 
            if(first == NULL){
                first = prev;
            }
            second = root;
        }
        prev = root;
        
        fixBST(root->right,prev,first,second);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;
        fixBST(root,prev,first,second);
        swap(first->val , second->val);
    }
};
