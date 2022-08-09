class Solution {
public:
    int mod = 1e9+7;
    unordered_map<TreeNode*,pair<long long int,long long int>> mp;
    long long int helper(TreeNode* root){
        if(!root)
            return 0;
        long long int ls = 0,rs = 0;
        if(root->left)
            ls = helper(root->left);
        if(root->right)
            rs = helper(root->right);
        mp[root] = {ls,rs};
        return ls+rs+root->val;
    }
    long long int ans = 0;
    void helper2(TreeNode* root,long long int adon){
        if(root == NULL)
            return;
        long long int x = root->val + adon;
        ans = max(ans,max((x+mp[root].first)*mp[root].second,(x+mp[root].second)*mp[root].first));
        helper2(root->left,x+mp[root].second);
        helper2(root->right,x+mp[root].first);
    }
    int maxProduct(TreeNode* root) {
        long long int x = helper(root);
        helper2(root,0);
        return ans%mod;
    }
};
