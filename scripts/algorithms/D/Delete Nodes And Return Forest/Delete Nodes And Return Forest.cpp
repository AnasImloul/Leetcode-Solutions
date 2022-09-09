// Runtime: 53 ms (Top 21.57%) | Memory: 25.2 MB (Top 76.05%)
class Solution {
    void solve(TreeNode* root,TreeNode* prev,unordered_map<int,int>& mp,int left,vector<TreeNode*>& ans){
        if(root==NULL)
            return;

        int f=0;

        solve(root->left,root,mp,1,ans);
        solve(root->right,root,mp,0,ans);

         if(mp.find(root->val)!=mp.end()){
            f=1;
            if(root->right)
                ans.push_back(root->right);
                // cout<<root->left->val<<" ";}
            if(root->left)
                ans.push_back(root->left);
                // cout<<root->right->val<<" ";}
        }

        if(f==1){
            if(left)
                prev->left=NULL;
            else
                prev->right=NULL;
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL)
            return {};

        unordered_map<int,int> mp;
        for(int i=0;i<to_delete.size();i++)
            mp[to_delete[i]]++;

       vector<TreeNode*> ans;

        TreeNode* dummy=new TreeNode(-1);
        dummy->left=root;

        solve(dummy->left,dummy,mp,1,ans);
        if(dummy->left)
        ans.push_back(root);

        return ans;
    }
};
        ```