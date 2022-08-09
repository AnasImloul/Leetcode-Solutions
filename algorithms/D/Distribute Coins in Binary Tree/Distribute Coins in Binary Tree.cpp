class Solution {
public:
    int ans = 0;
    int recr(TreeNode *root)
    {
        if(!root) return 0;
        int left = recr(root->left);
        int right = recr(root->right);
        int curr = root->val + left + right;
        ans += abs(curr-1);
        return curr-1;
    }
    int distributeCoins(TreeNode* root) {
        recr(root);
        return ans;
    }
};
