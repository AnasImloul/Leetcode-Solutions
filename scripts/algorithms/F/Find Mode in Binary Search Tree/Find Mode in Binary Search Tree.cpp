// Runtime: 20 ms (Top 91.73%) | Memory: 25.3 MB (Top 59.17%)
class Solution {
public:

    void inorder(TreeNode* root, unordered_map<int,int>& mp){
        if(root==NULL) return;

        inorder(root->left, mp);
        mp[root->val]++;
        inorder(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        int maxf=INT_MIN;
        vector<int> ans;

        inorder(root, mp);

        for(auto i=mp.begin(); i!=mp.end(); i++){
            maxf = max(i->second, maxf);
        }

        for(auto i=mp.begin(); i!=mp.end(); i++){
            if(i->second==maxf) ans.push_back(i->first);
        }

        return ans;

    }
};