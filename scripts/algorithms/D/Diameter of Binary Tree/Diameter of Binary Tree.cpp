// Runtime: 19 ms (Top 46.08%) | Memory: 20.1 MB (Top 92.89%)
class Solution {

     int solve(TreeNode* root, int &dia) {
        if(root == NULL) return 0;
        int lh = solve(root->left, dia);
        int rh = solve(root->right, dia);
        dia=max(dia,lh+rh);
        return max(lh,rh)+1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        solve(root, dia);
        return dia;
    }
};