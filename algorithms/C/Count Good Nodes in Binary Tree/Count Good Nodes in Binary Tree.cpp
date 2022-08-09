
class Solution {
public:
    int count=0;
    void sol(TreeNode* root,int gr){
        if(!root)return;  // base condition 
       
        if(gr<=root->val){  //check point max element increase count
            gr=max(gr,root->val);
            count++;
        }
        
        if(root->left) sol(root->left,gr);
        if(root->right) sol(root->right,gr);
        
    }
    int goodNodes(TreeNode* root) {
        
        if(!root->left && !root->right) return 1; //check for if there is one node
        int gr=root->val;
        sol(root,gr);
        return count;
        
    }
};
