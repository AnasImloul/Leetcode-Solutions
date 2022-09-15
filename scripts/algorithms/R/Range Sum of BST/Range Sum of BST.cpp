// Runtime: 235 ms (Top 36.09%) | Memory: 64.6 MB (Top 92.35%)
class Solution {
public:

    int solve(TreeNode* root, int low, int high){
        if(root == NULL)
            return 0;

        int sum = 0;
        if(low <= root->val && root->val <= high){
            sum = root->val;
        }

        return sum + solve(root->left, low, high) + solve(root->right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {

        return solve(root, low, high);
    }
};