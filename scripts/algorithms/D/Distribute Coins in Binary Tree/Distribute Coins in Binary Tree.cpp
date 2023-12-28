// Runtime: 10 ms (Top 18.75%) | Memory: 14.30 MB (Top 15.52%)

class Solution {
public:
    
    // calculate required moves in postorder manner
    int traverse(TreeNode* root, int &moves)
    {
        if(!root) return 0;
        
        // left subtree excess amount coin
        int left = traverse(root->left,moves);
        
        // right subtree excess amount coin
        int right = traverse(root->right,moves);
        
        // moves needed to neutralize the excess amount of coins of left and right subtree
        moves += abs(left) + abs(right);
        
        // current subtree including current root excess amount is 
        // total coins in the subtree - total nodes in the subtree
        // left and right subtree excess amount coin + root coin -1
        return root->val + left + right -1;
    }
    
    int distributeCoins(TreeNode* root) {
        
        int moves = 0;
        traverse(root,moves);
        return moves;
    }
};
