// Runtime: 90 ms (Top 5.5%) | Memory: 37.50 MB (Top 5.0%)

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
     void sol(TreeNode *root, string &s){
         queue<TreeNode*> q;
         q.push(root);
         s+=to_string(root->val);
         while(!q.empty()){
             auto x=q.front(); q.pop();
             if(x->left){
                 
               s+=to_string( x->left->val);   
               q.push(x->left);
             }else if(!x->left){
                 s+='#';
             }
              if(x->right){
                   s+=to_string( x->right->val);
                   q.push(x->right);
              }else if(!x->right){
                  s+='#';
              }
             
         }
     }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        string s;
        sol(subRoot, s);
        cout<<s<<" ";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto x=q.front(); q.pop();
            if(x->val==subRoot->val){
                string k;
                sol(x, k);
                cout<<k<<" ";
              bool  istrue=false;
                if(k.size()==s.size()){
                for(int i=0; i<k.size(); i++){
                    if(k[i]!=s[i]){
                        istrue=true;
                    }
                }
                if(istrue==false){
                    return true;
                }
                }
            }
            if(x->left){
                q.push(x->left);
            }
            if(x->right){
                q.push(x->right);
            }
        }
        return false;
    }
};