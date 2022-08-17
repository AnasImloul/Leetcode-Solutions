class Solution {
public:
    unordered_map<int,vector<TreeNode*>> dp;
    int hash(int i,int j){
        return (i*21 + j);
    }
    vector<TreeNode*> fn(int l,int r){
        int has = hash(l,r);
        if(dp.find(has)!=dp.end()){
            return dp[has];
        }
        vector<TreeNode*> res;
        if(r<l){
            return {NULL};
        }
        if(r==l){
            return {new TreeNode(0)};
        }
        for(int i = l+1;i<r;i++){
             vector<TreeNode*> left =  fn(l,i-1);
            vector<TreeNode*> right =  fn(i+1,r);
              for(auto le:left){
                for(auto ri:right ){
                    TreeNode* temp = new TreeNode(0);
                    temp->left = le;
                    temp->right = ri;
                    res.push_back(temp);
                }
            }
        }
        return dp[has] = res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return fn(1,n);
    }
