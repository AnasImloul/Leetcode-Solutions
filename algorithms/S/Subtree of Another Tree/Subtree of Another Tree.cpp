class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1 = convertToString(root);
        string s2 = convertToString(subRoot);
        return s1.find(s2) != string::npos;
    }
    
    string convertToString(TreeNode* node) {
        if(node == NULL) return "NULL,";
        return "[" + to_string(node->val) + "]" + "," + convertToString(node->left) + convertToString(node->right);
    }
};
