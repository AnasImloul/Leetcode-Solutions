// Runtime: 38 ms (Top 5.39%) | Memory: 22.80 MB (Top 76.84%)

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while (q.size()) {
            double qlen = q.size(), row = 0;
            for (int i = 0; i < qlen; i++) {
                TreeNode* curr = q.front(); q.pop();
                row += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            ans.push_back(row/qlen);
        }
        return ans;
    }
};
