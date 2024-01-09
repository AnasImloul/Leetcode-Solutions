// Runtime: 123 ms (Top 79.62%) | Memory: 94.50 MB (Top 70.02%)

class Solution {
    public:
    int maxLength=0;

    void solve(TreeNode* root,int dir,int currLength){
        if(!root) return;
        maxLength=max(maxLength,currLength);
        solve(root->left,0,dir?currLength+1:1);
        solve(root->right,1,dir?1:currLength+1);
    }

    int longestZigZag(TreeNode* root) {
        solve(root,0,0);
        solve(root,1,0);
        return maxLength;
    }
};
