class Solution {
public:
    int ans=0;
    void dfs(TreeNode* root, string s){
        if(!root->left && !root->right){
            s+=to_string(root->val);
            ans+=stoi(s);
            return;
        }
        string o = s;
        s+=to_string(root->val);
        if(root->left) dfs(root->left,s);
        if(root->right) dfs(root->right,s);
        s=o;
        
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return ans;
        string s = "";
        dfs(root,s);
        return ans;
    }
};
