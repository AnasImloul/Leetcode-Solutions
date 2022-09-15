// Runtime: 9 ms (Top 7.20%) | Memory: 7.1 MB (Top 26.56%)
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        while(!q.empty()){
            v.push_back(q.front()->val);
            if(q.front()->left){
                q.push(q.front()->left);
            }
            if(q.front()->right){
                q.push(q.front()->right);
            }
            q.pop();
        }
        sort(v.begin(),v.end());
        int ans=-1;
        for(int i=1;i<v.size();i++){
            if(v[i]!=v[0]){
                return v[i];
            }
        }
        return ans;
    }
};