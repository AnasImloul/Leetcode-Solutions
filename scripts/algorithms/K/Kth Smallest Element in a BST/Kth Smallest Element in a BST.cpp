// Runtime: 36 ms (Top 27.23%) | Memory: 24.3 MB (Top 34.42%)
class Solution {
public:
    void findInorder(TreeNode* root, vector<int> &ans) {
        if(root == NULL)
            return;

        findInorder(root->left, ans);
        ans.push_back(root->val);
        findInorder(root->right, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        findInorder(root, ans);
        return ans[k-1];
    }
};