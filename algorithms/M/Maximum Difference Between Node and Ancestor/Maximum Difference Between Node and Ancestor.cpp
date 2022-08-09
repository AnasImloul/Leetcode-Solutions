class Solution {
private:
    int maxDiff;
    pair <int, int> helper(TreeNode* root) {
        if (root == NULL) return {INT_MAX, INT_MIN};
        pair <int, int> L = helper(root -> left), R = helper(root -> right);
        pair <int, int> minMax = {min(L.first, R.first), max(L.second, R.second)};
        if (minMax.first != INT_MAX) maxDiff = max(maxDiff, max(abs(root -> val - minMax.first), abs(root -> val - minMax.second)));
        return {min(root -> val, minMax.first), max(root -> val, minMax.second)};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        maxDiff = INT_MIN;
        helper(root);
        return maxDiff;
    }
};
