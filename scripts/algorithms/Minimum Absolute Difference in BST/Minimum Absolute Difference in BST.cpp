class Solution {
    TreeNode* pre = nullptr;
    int minimum = std::numeric_limits<int>:: max();
public:
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if(pre) {
            minimum = min(node->val - pre->val, minimum);
        }
        pre = node;
        inorder(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minimum;
    }

};
