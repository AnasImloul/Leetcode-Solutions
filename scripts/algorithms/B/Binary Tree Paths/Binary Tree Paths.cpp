// Runtime: 3 ms (Top 89.27%) | Memory: 13.9 MB (Top 17.11%)
class Solution {
private:
    void dfs(TreeNode* root,string s,vector<string> &ans){
        if(root == NULL) return;

        s += (to_string(root -> val));

        if(root -> left != NULL || root -> right != NULL) s += "->";

        if(root -> left == NULL and root -> right == NULL) {
            ans.push_back(s);
        }

        dfs(root -> left,s,ans);
        dfs(root -> right,s,ans);
        s.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;
        string s;
        dfs(root,s,ans);
        return ans;

    }
};