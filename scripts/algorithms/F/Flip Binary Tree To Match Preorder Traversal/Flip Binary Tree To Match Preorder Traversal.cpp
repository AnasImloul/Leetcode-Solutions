// Runtime: 4 ms (Top 80.72%) | Memory: 13.8 MB (Top 73.01%)
class Solution {
public:

    bool helper(int &ind, TreeNode *root, vector<int> &voyage, vector<int> &ans){
        if(root == NULL || ind == voyage.size()){
            ind--;
            return true;
        }

        // Not possible to create
        if(root->val != voyage[ind]){
            ans.clear();
            ans.push_back(-1);
            return false;
        }

        // If voyage value not equal to its left child, then swap both childs and check
        if(root->left && root->left->val != voyage[ind+1]){
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;

            // Pusing root into ans
            ans.push_back(root->val);
        }

        return helper(++ind, root->left, voyage, ans) &&
            helper(++ind, root->right, voyage, ans);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int ind = 0;
        vector<int> ans;
        helper(ind, root, voyage, ans);
        return ans;
    }
};