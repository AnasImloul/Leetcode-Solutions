class Solution {
public:
    
    bool prune(TreeNode *root, int limit, int sum){
            
        if(root->left == NULL && root->right == NULL){
            //Signal to you parent if you lie within the limit or not
            if(root->val+sum >= limit) return true;
            else return false;
        }
        
        //Wait for signal from left subtree
        bool lf = root->left ? prune(root->left, limit, sum+root->val): false;
        
		//Wait for signal from right subtree
        bool rt = root->right ? prune(root->right, limit, sum+root->val) : false;
        
		//If false the node need to GO
        if(lf == false) root->left = NULL;
        if(rt == false) root->right = NULL;
            
		//Now signal to your parent
        return lf | rt;
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
        bool stat = prune(root, limit, 0);
		//If the whole tree doesn't lie within the Limit
        if(stat == true) return root;
        else return nullptr;
        
    }
	
};
