/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string res;
    void solve(TreeNode* root,string cur){
        if(!root) return;
        cur.push_back((char)('a'+root->val));//converting integer to corresponding characer
        if(!root->left and !root->right){
			//reversing the string since it is computed from root to leaf, but we need viceversa
            reverse(cur.begin(),cur.end());
            if(res=="" or cur<res) res=cur;//updating the result based on lexicographical order
            return;
        }
        solve(root->left,cur);
        solve(root->right,cur);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return ""; 
        solve(root,"");
        return res;
    }
};
