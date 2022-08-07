class Solution {
    void dft(TreeNode* root, int level, map<int,vector<int>,std::greater<int>>& levelVals)
    {
        if (root == nullptr)
            return;
        
        if (levelVals.find(level) == levelVals.end())
            levelVals[level] = {root->val};
        else
            levelVals[level].push_back(root->val);
        
        dft(root->left,level+1,levelVals);
        dft(root->right,level+1,levelVals);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        map<int,vector<int>,std::greater<int>> levelVals;
        dft(root,0,levelVals);
        
        vector<vector<int>> res;
        for (const auto& [level,vals] : levelVals)
            res.push_back(vals);
        
        return res;
    }
};
