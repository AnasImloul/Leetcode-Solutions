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
    
    /*  How to get LeafOrder?
        Simply traverse the tree Left->right
        whenever you get a leaf, push its value to a vector
    */
    
    
    void getLeafOrder(TreeNode* root, vector<int> &leafOrder){  // Here we are passing vector
        if(root == NULL){                                       // by reference to make changes
            return;                                             // directly in main vector
        }
        
        // Leaf found -> push its value in the vector
        if(root->left == NULL and root->right == NULL){
            leafOrder.push_back(root->val);
            return;
        }
        
        getLeafOrder(root->left, leafOrder);    // Left then Right -> to maintain the sequence
        getLeafOrder(root->right, leafOrder);
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafOrder1;
        vector<int> leafOrder2;
        
        getLeafOrder(root1, leafOrder1);    // Get leaf order for both trees
        getLeafOrder(root2, leafOrder2);
        
        return leafOrder1 == leafOrder2;    // return if they are equal or not
    }
};
