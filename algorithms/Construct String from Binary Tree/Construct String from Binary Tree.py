class Solution {
    void tree2str(TreeNode* root,string &s) {
        if(!root) return;
        
        s+=to_string(root->val);
        
        if(!root->left && !root->right) return;
        
        s.push_back('('); tree2str(root->left,s); s.push_back(')');
        
        if(root->right){
            s.push_back('('); tree2str(root->right,s); s.push_back(')');
        }
    } 
public:
    string tree2str(TreeNode* root) {
        string ans = "";
        tree2str(root,ans);
        return ans;
    }
};
