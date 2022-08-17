class Solution {
public:
    bool ans=false;
      int sum=0;
    void recur(TreeNode* root, int target){
        if(root==NULL)return;
        
            sum+=root->val;
            recur(root->left,target);
            recur(root->right,target);
           if(root->left==NULL && root->right==NULL&&sum == target){ // !!Check only if it is a leaf node....
             ans = true;
             return;
            }
            sum-=root->val; //backtracking
            return;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        recur(root,targetSum);
        return ans;
    }
};
