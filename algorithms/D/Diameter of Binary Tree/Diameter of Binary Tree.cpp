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
