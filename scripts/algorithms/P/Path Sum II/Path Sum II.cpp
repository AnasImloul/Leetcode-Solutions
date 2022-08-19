// Runtime: 24 ms (Top 43.53%) | Memory: 20 MB (Top 62.29%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> v;
    void helper(vector<int>& t, int target, TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL&&target==root->val){
            t.push_back(root->val);
            v.push_back(t);
            t.pop_back();
            return;
        }
        target=target-root->val;
        t.push_back(root->val);
        helper(t,target,root->left);
        helper(t,target,root->right);
        t.pop_back();

        //cout<<root->val<<" "<<target<<endl;
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> t;
        helper(t,targetSum,root);
        return v;
    }
};