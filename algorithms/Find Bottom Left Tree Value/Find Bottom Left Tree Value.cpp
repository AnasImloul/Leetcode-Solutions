class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=root->val;
        
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr= q.front();
                q.pop();
                
                if(i==0) ans=curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return ans;
    }
};
