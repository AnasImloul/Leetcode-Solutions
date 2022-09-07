// Runtime: 13 ms (Top 20.00%) | Memory: 13.5 MB (Top 62.44%)
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

    void insertIntoMaxTreeRec(TreeNode* root,TreeNode* newNode)//o(logn)
    {

        if(!root)
            return;
        if(root->right&&root->right->val<newNode->val)
        {
            newNode->left=root->right;
            root->right=newNode;

            return;

        }
        if(!root->right)
        {root->right=newNode;

        return;}

         insertIntoMaxTreeRec( root->right, newNode);

    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
         TreeNode* curr=new TreeNode(val);

        if(root->val<val)
        {
            curr->left=root;
            root=curr;
        }else
        {
              insertIntoMaxTreeRec( root, curr);

        }
        return root;

    }
};