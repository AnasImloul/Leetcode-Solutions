// Runtime: 0 ms (Top 100.00%) | Memory: 8.6 MB (Top 12.25%)
class Solution {
public:
    vector<vector<string>> res;

    int height(TreeNode* root){
        if(!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    void fill(TreeNode* root, int r, int c, int h){
        if(!root)
            return;
        res[r][c] = to_string(root->val);
        fill(root->left, r + 1, c - pow(2, h - r - 1), h);
        fill(root->right, r + 1, c + pow(2, h - r - 1), h);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int c = pow(2, h) - 1;
        res.resize(h, vector<string>(c, ""));
        fill(root, 0, (c - 1) / 2, h - 1);
        return res;
    }
};