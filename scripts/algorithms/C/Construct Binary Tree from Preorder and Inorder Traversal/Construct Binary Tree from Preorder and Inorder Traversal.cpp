// Runtime: 37 ms (Top 52.12%) | Memory: 26.5 MB (Top 17.39%)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    typedef vector<int>::iterator vecIt;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, TreeNode* retNode, vecIt startIt, vecIt endIt)
    {
        if (startIt >= endIt)
            return (NULL);
        vecIt rootIt;
        vecIt midIt;
        int rootVal;

        rootIt = preorder.begin();
        rootVal = *rootIt;
        preorder.erase(rootIt);
        retNode = new TreeNode(rootVal);
        midIt = find(startIt, endIt, rootVal);
        retNode->left = buildTree(preorder, inorder, retNode->left, startIt, midIt);
        retNode->right = buildTree(preorder, inorder, retNode->right, midIt + 1, endIt);
        return (retNode);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* retNode;

        return (buildTree(preorder, inorder, retNode, inorder.begin(), inorder.end()));
    }
};