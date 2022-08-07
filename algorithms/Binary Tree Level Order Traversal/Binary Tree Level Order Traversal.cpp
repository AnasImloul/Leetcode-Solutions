class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       queue<TreeNode *>q;
        vector<vector<int>> result;
        if(root==NULL) return result;
        q.push(root);
        q.push(NULL);
        vector<int>temp;
        while(!q.empty())
        {
            TreeNode *top = q.front();
            q.pop();
            if(top==NULL)
            {
                result.push_back(temp);
                temp.clear();
                if(!q.empty())
                {
                    q.push(NULL);
                    continue;
                }
                return result;               
            }
            else temp.push_back(top->val);                            
            
            if(top->left) q.push(top->left);                
               
            if(top->right) q.push(top->right);            
        }
        
        return result;
    }
};
