class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == target || original == NULL)
            return cloned;
        TreeNode* found_left = getTargetCopy(original->left, cloned->left, target);
        TreeNode* found_right = getTargetCopy(original->right, cloned->right, target);
        if(found_left)
            return found_left;
        else
            return found_right;
    }
};
