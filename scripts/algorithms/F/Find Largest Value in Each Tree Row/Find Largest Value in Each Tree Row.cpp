// Runtime: 3 ms (Top 99.90%) | Memory: 22.1 MB (Top 68.12%)
class Solution {
public:
    vector<int>res;
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        if(!root->left && !root->right) return {root->val};
        TreeNode*temp;
        int mx = INT_MIN;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                temp = q.front();
                if(temp->val > mx) mx = temp->val;
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(mx);
            mx = INT_MIN;
        }
        return res;
    }
};