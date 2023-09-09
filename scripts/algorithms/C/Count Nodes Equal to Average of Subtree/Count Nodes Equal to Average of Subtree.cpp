// Runtime: 3 ms (Top 95.3%) | Memory: 11.96 MB (Top 50.2%)

class Solution {
public:
    pair<int,int> func(TreeNode* root,int &ans){
        if(!root)return {0,0};
        auto p1=func(root->left,ans);
        auto p2=func(root->right,ans);
        int avg=(root->val+p1.first+p2.first)/(p1.second+p2.second+1);
        if(avg==root->val)ans++;
        return {root->val+p1.first+p2.first,p1.second+p2.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        func(root,ans);
        return ans;
    }
};