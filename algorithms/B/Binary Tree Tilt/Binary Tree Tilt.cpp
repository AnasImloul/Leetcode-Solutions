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
    
    /*  We will take help of recursion
        Each function call will return the sum of subtree with root as current root
        and the tilt sum will be updated in the variable passed as reference
    */
    
    int getTiltSum(TreeNode* root, int &tiltSum){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL and root->right == NULL){     // If we have a leaf
            tiltSum+=0;         // Add nothing to tilt sum
            return root->val;   // return its value as sum
        }
        
        int leftSubTreeSum = getTiltSum(root->left, tiltSum);   // Sum of all nodes in left
        int rightSubTreeSum = getTiltSum(root->right, tiltSum); // and right subtrees
        
        tiltSum += abs(leftSubTreeSum - rightSubTreeSum);   // Update the tilt sum
        
        // return the sum of left Subtree + right subtree + current node as the sum of the 
        return (root->val + leftSubTreeSum + rightSubTreeSum);  // subtree with root as current node.
        
    }
    
    
    int findTilt(TreeNode* root) {
        // variable to be passed as refrence and store the result
        int tiltSum = 0;
        
        getTiltSum(root, tiltSum);
        
        return tiltSum;
    }
};
