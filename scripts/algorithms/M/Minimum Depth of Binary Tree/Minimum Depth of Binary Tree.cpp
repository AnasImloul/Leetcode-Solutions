// Runtime: 480 ms (Top 20.84%) | Memory: 144.6 MB (Top 72.25%)
class Solution {
public:
    void maxlevel(TreeNode* root,int level,int &ans){
        if(!root)
            return ;

        if(!root->left && !root->right){
            ans=min(level,ans);
            return ;
        }

        maxlevel(root->left,level+1,ans);
        maxlevel(root->right,level+1,ans);
    }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;

        int ans=INT_MAX;
        maxlevel(root,0,ans);
        return ans+1;
    }
};