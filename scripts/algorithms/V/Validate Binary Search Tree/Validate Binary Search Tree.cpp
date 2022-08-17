// We know inorder traversal of BST is always sorted, so we are just finding inorder traversal and check whether it is in sorted manner or not, but only using const space using prev pointer.
class Solution {
public:
    TreeNode* prev;
    Solution(){
        prev = NULL;
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        bool a = isValidBST(root->left);
        if (!a)
            return false;
        if (prev != NULL)
        {
            if (prev->val >= root->val)
                return false;
        }
        prev = root;
        return isValidBST(root->right);
    }
};
