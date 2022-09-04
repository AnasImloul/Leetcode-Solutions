// Runtime: 46 ms (Top 11.65%) | Memory: 24.7 MB (Top 31.13%)
class Solution {
private:
    unordered_map<int, int> m;
    int maxi = 0;
    int f(TreeNode* root){
        if(!root) return 0;
        int l = f(root->left);
        int r = f(root->right);
        int sum = root->val + l + r;
        m[sum]++;
        maxi = max(maxi, m[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        f(root);
        for(auto &e : m){
            if(e.second == maxi) ans.push_back(e.first);
        }
        return ans;
    }
};