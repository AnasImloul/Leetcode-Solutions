/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void help(TreeNode* root, TreeNode* par, map<TreeNode*,TreeNode*> &m)
    {
        if(root==NULL)
            return;
        m[root]=par;
        help(root->left,root,m);
        help(root->right,root,m);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        TreeNode* r=root;
        map<TreeNode*,TreeNode*>m;
        help(r,NULL,m);
        queue<TreeNode*>q;
        vector<TreeNode*>ans;
        q.push(root);  
        while(!q.empty())
        {
            int s=q.size();
            vector<TreeNode*>a;
            for(int i=0;i<s;i++)
            {
                TreeNode* bgn=q.front();
                q.pop();
                a.push_back(bgn);
                if(bgn->left!=NULL)
                    q.push(bgn->left);
                if(bgn->right!=NULL)
                    q.push(bgn->right);
            }
            ans=a;
        }
        if(ans.size()==1)
            return ans[0];
        set<TreeNode*>s;
        while(s.size()!=1)
        {
            s.clear();
            for(int i=0;i<ans.size();i++)
            {
                ans[i]=m[ans[i]];
            }
            s.insert(ans.begin(),ans.end());
        }
        for(auto i : s)
        {
            return i;
        }
        return NULL;
    }
};
