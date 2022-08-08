
class Solution {
public:
    
    stack<TreeNode *>st;
    
    vector<TreeNode * >vec;
    int mx = INT_MIN;
    
    void ch(TreeNode * root, int h){
        if(!root) return ;
        ch(root->left, h+1);
        ch(root->right, h+1);
        
        if(h==mx){
            vec.push_back(root);
        }
        else if(h>mx){
            vec.clear();
            vec.push_back(root);
            mx = h;
        }
    }
    
    bool uf = 0;
    
    void check(TreeNode * root, TreeNode * it){
        
        if(!root or uf) return ;
        
        st.push(root);
        
        if(root->val == it->val){
            uf = 1;
            return ;
        }
        
        check(root->left, it);
        check(root->right, it);
        
        if(!uf)
            st.pop();
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vec.clear();
        ch(root, 0);
        vector<vector<TreeNode *>>ans;
        ans.clear();
        int mnx = INT_MAX;
        for(auto it:vec){
            uf = 0;
            check(root, it);
            vector<TreeNode *>temp;
            
            while(!st.empty()){
                temp.push_back(st.top());
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            int p = temp.size();
            mnx = min(mnx, p);
        }
        
        TreeNode * rt = new TreeNode(0);
        if(ans.size() == 1){
            return ans[0][ans[0].size()-1];
        }
        bool lb = 0;
        
        
        for(int j=0; j<mnx; j++){
            for(int i=0; i<ans.size()-1; i++){
                
                if(ans[i][j]==ans[i+1][j]){
                    continue;
                }
                else{
                    rt = ans[i][j-1];
                    lb = 1;
                    break;
                }
            }
            if(lb) break;
        }
        
        return rt;
        
    }
};

