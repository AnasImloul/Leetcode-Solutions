// Runtime: 722 ms (Top 5.05%) | Memory: 169.4 MB (Top 18.67%)
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL) return true;
        q.push(root);
        int j=0;
        while(q.empty()!=true)
        { vector<int>v;
            int n=q.size();
            for(int i=0;i<n;i++)
            { TreeNode* t=q.front();q.pop();
                v.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
         if(j%2==0)
         {
             for(int k=0;k<v.size()-1;k++)
             {
                 if(v[k]%2==0)
                     return false;
                 if(v[k]>=v[k+1])
                     return false;
             }
             if(v[v.size()-1]%2==0)
                 return false;
         }
         else
         {
              for(int k=0;k<v.size()-1;k++)
             {
                 if(v[k]%2==1)
                     return false;
                 if(v[k]<=v[k+1])
                     return false;
             }
             if(v[v.size()-1]%2==1)
                 return false;
         }
         j++;
            ans.push_back(v);
        }
        return true;
    }
};