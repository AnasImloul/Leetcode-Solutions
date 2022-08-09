class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        if(root->val < low){
            if(root->right){
                TreeNode* temp = root;
                // delete root;
                return temp->right;
            }else{
                return NULL;
            }
        }
        if(root->val > high){
            if(root->left){
                TreeNode* temp = root;
                // delete root;
                return temp->left;
            }else{
                return NULL;
            }
        }
        return root;
    }
};
