class Solution {
public:
    int ans = 0,t;
    
    void dfs(unordered_map<long long,int> &curr,TreeNode* node,long long sm){
        
        if(!node){
            return;
        }
                
        sm += (long long) node->val;
        ans += curr[sm-t];
        curr[sm]++;
                
        dfs(curr,node->left,sm);
        dfs(curr,node->right,sm);
        
        curr[sm]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        
        t = targetSum;
        unordered_map<long long,int> curr;
        curr[0] = 1;
        long long sm = 0;
        
        dfs(curr,root,sm);

        return ans;
    }
};
