// Runtime: 0 ms (Top 100.0%) | Memory: 14.40 MB (Top 7.7%)

class Solution {
public:
    //Isommorphic tree 
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2) return true ;
        if(!root1 or  !root2) return false ;
        if(root1->val != root2->val) return false ;
        
        //if flipped then  left subtree == right subtree and right subtree == left subtree 
        bool a = flipEquiv(root1->left,root2->right) ;
        bool b = flipEquiv(root1->right,  root2->left) ;
        
        // if not flipped then left subtree == left subtree and right subtree == right subtree
        bool aa = flipEquiv(root1->left,root2->left) ;
        bool bb = flipEquiv(root1->right,root2->right) ;
        
        return (a and b) || (aa and bb );
    }
};
