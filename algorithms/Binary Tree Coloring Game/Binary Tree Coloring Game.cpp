class Solution {
public:
    // nodex means "node with val = x" 
    // Idea behind this is to block either nodex's parent or it's left child or right child. Block means we will chose that node as nodey. Why? because it will devide the tree in two parts, one for player 1 and other for player 2. Then we have to just take the maximum no of nodes we can get, from these three nodes as head, and if max is greater than n/2, means we can will.
    TreeNode *nodex, *parentx;
    Solution(){
        nodex = NULL;
        parentx = NULL;
    }
    int count(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int a = count(root->left);
        int b = count(root->right);
        return a + b + 1;
    }
    bool findx(TreeNode *root, int x)
    {
        if (root == NULL)
            return false;
        parentx = root;
        if (root->val == x)
        {
            nodex = root;
            return true; 
        }
        bool a = findx(root->left, x);
        if (a)
            return true;
        bool b = findx(root->right, x);
        return b;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        findx(root, x); // Find the node which has val = x
        int p = n - count(nodex); // Count the no of nodes of blue color, if we decide to take parent of nodex as nodey
        int r = count(nodex->right); // Count the no of nodes of blue color, if we decide to take right child of nodex as nodey
        int l = count(nodex->left); // Count the no of nodes of blue color, if we decide to take left child of nodex as nodey
        int mx = max(p,r);
        mx = max(mx, l); // max of all three possible scenarios
        if (mx > n/2)
            return true;
        else
            return false;
    }
};
