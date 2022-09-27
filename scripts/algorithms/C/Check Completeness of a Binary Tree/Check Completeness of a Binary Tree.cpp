// Runtime: 7 ms (Top 64.29%) | Memory: 10.3 MB (Top 76.53%)
class Solution {
public:
    bool isComplete = true;

    // Returns min, max height of node
    pair<int,int> helper(TreeNode *root){
        // NULL is of height zero
        if(root == NULL){
            return {0, 0};
        }

        // Moving to its children
        pair<int,int> lst = helper(root->left);
        pair<int,int> rst = helper(root->right);

        // Height of rst is greater than lst or
        // There are levels which are not filled other than the last level (diff between levels > 1)
        if(rst.second > lst.first || lst.second - rst.first > 1){
            isComplete = false;
        }

        return {min(lst.first, rst.first)+1, max(lst.second, rst.second)+1};
    }

    bool isCompleteTree(TreeNode* root) {
        helper(root);
        return isComplete;
    }
};