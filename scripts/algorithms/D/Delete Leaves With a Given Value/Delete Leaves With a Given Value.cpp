// Runtime: 43 ms (Top 7.25%) | Memory: 21.8 MB (Top 63.99%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL || root->left == NULL && root->right == NULL && root->val == target)
            return NULL;

        root->left = removeLeafNodes(root->left,target);
        root->right = removeLeafNodes(root->right,target);

        if(root->left == NULL && root->right == NULL && root->val == target)
        {
            return NULL;
        }

        return root;

    }
};