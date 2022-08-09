class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* node = root;
        while(true){
            if(val>=node->val){
                if(node->right) node = node->right;
                else{
                    node->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(node->left) node = node->left;
                else{
                    node->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
