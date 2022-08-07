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
