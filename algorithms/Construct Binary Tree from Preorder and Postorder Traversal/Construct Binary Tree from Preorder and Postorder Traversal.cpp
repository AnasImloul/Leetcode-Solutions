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
    bool vis[40];
    
    TreeNode* solve(vector<int>& pre,int p, vector<int>& pos,int q){
        TreeNode* root=new TreeNode(pre[p]);
        vis[pre[p]]=true;
        p++;
        q--;
        
        if(p>=pre.size() || q<0){
            return root;
        }
        if(!vis[pre[p]]){
            
            int x=q;
            while(x>0 and pos[x]!=pre[p])x--;
            if(pos[x]==pre[p]){
                root->left=solve(pre,p,pos,x);
            }
            
        }
        if(!vis[pos[q]]){
            int x=p;
            while(x<pre.size()-1 and pos[q]!=pre[x])x++;
            if(pos[q]==pre[x]){
                root->right=solve(pre,x,pos,q);
            }
        }
        return root;
    }
        
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=postorder.size();
        return solve(preorder,0,postorder,n-1);
    }
};
