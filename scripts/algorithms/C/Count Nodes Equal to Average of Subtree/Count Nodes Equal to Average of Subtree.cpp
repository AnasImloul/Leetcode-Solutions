class Solution {
public:    
    int count(TreeNode* root)
    {
        //if tree is empty
        if(root==NULL) return 0;
        
        //if tree has single node/leaf node
        if(root->left==NULL && root->right==NULL) return 1;    
        
        return 1 + count(root->left) + count(root->right);
    }
    
    
    int sum(TreeNode* root)
    {
        //if tree is empty
        if(root==NULL) return 0;
        
        return root->val + sum(root->left) +  sum(root->right);
    }
    
    int averageOfSubtree(TreeNode* root) {
        
        //if tree is empty
        if(root==NULL) return 0;
        
        //if tree has single node/leaf node
        if(root->left==NULL && root->right==NULL) return 1;
        
        //return value or Boolean condition(1 or 0) + rec(root->left) + rec(root->right)
        return (sum(root)/count(root)==root->val) + averageOfSubtree(root->left) + averageOfSubtree(root->right);

    }
};
