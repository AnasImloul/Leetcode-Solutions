// Runtime: 417 ms (Top 23.94%) | Memory: 115.2 MB (Top 59.95%)
class Solution {
public:
    bool search(TreeNode* root, int target, string &s){
        if(root==NULL) {
            return false;
        }
        if(root->val==target) {
            return true;
        }

        bool find1=search(root->left,target, s+='L'); // search on left side
        if(find1) return true;
        s.pop_back(); // backtracking step

        bool find2= search(root->right,target, s+='R'); // search on right side
        if(find2) return true;
        s.pop_back(); // backtracking step
        return false;
    }

     TreeNode* lca(TreeNode* root ,int n1 ,int n2)
    {
       if(root==NULL)
       return NULL;
       if(root->val==n1 or root->val==n2)
       return root;

       TreeNode* left=lca(root->left,n1,n2);
       TreeNode* right=lca(root->right,n1,n2);

       if(left!=NULL && right!=NULL)
       return root;
       if(left)
       return left;
       if(right)
       return right;

       return NULL; // not present in tree

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* temp=lca(root,startValue,destValue);

        string s1,s2;
        search(temp,startValue,s1);
        search(temp,destValue,s2);
        for(auto &it:s1){
            it='U';
        }
        return s1+s2;
    }
};