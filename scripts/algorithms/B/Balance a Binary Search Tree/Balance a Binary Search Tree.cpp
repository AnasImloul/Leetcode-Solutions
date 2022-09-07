// Runtime: 305 ms (Top 25.60%) | Memory: 63.3 MB (Top 34.89%)
class Solution {
public:
    vector<int> nums ;
    void traverse(TreeNode * root){
        if(!root) return ;
        traverse(root->left) ;
        nums.push_back(root->val) ;
        traverse(root->right) ;
        return ;
    }

    TreeNode * makeTree(int s , int e){
        if(s > e) return nullptr ;
        int m = (s + e) / 2 ;
        TreeNode * root = new TreeNode(nums[m]) ;

        root->left = makeTree(s,m - 1) ;
        root->right = makeTree(m + 1,e) ;

        return root ;
    }

    TreeNode* balanceBST(TreeNode* root) {
        traverse(root) ;
        return makeTree(0,size(nums) - 1) ;
    }
};