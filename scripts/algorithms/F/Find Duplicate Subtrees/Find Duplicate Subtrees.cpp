// Runtime: 41 ms (Top 93.16%) | Memory: 44.5 MB (Top 70.83%)
class Solution {
public:
    unordered_map<string,int> dp ;
    vector<TreeNode*> ans ;

    string solve(TreeNode * root){
        if(!root) return "" ;

        string left = solve(root->left) ;
        string right = solve(root->right) ;

        string code = to_string(root->val) + " " + left + " " + right ;
        if(dp[code] == 1) ans.push_back(root) ;
        dp[code]++ ;

        return code ;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string dummy = solve(root) ;
        return ans ;
    }
};