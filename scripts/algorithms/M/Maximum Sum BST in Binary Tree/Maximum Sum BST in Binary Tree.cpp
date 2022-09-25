// Runtime: 178 ms (Top 94.41%) | Memory: 113.3 MB (Top 38.78%)
class Solution {
public:
    int ans = 0 ;

    array<int,4> solve(TreeNode * root){
        if(!root) return {1,0,INT_MIN,INT_MAX} ;

        array<int,4> l = solve(root->left) ;
        array<int,4> r = solve(root->right) ;

        if(l[0] and r[0]){
            if(root->val > l[2] and root->val < r[3]){
                ans = max({ans,l[1],r[1]}) ;
                return {1,l[1] + r[1] + root->val,max({root->val,l[2],r[2]}),min({root->val,l[3],r[3]})} ;
            }
        }

        return {0,max(l[1],r[1]),INT_MIN,INT_MAX} ;
    }

    int maxSumBST(TreeNode* root) {
        auto arr = solve(root) ;
        return max(ans,arr[1]) ;
    }
};