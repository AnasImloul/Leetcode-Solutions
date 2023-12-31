// Runtime: 7 ms (Top 96.14%) | Memory: 25.40 MB (Top 77.88%)

class Solution {
public:
    int inorder(TreeNode* root, int& prevElement, int& ans){

        if(root->left) inorder(root->left, prevElement, ans);
        if(prevElement >=0 ) ans = min(ans, abs(prevElement-root->val));
        prevElement = root->val;
        if(root->right) inorder(root->right, prevElement, ans);

        return ans;      


    }
    int getMinimumDifference(TreeNode* root){
        int prevElement = -1;
        int ans = INT_MAX;
        return inorder(root, prevElement, ans);
     
    }
};
