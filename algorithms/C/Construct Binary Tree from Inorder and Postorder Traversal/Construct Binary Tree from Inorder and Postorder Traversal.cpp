/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    typedef vector<int>::iterator vecIt;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, vecIt start, vecIt end)
    {
        if (start >= end)
            return NULL;
        vecIt rootIt = postorder.end() - 1;
        int rootVal = *rootIt;
        postorder.erase(rootIt);
        TreeNode* newNode = new TreeNode(rootVal);
        vecIt midIt = find(start, end, rootVal);
        newNode->right = buildTree(inorder, postorder, midIt + 1, end);
        newNode->left = buildTree(inorder, postorder, start, midIt);
        return (newNode);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return (buildTree(inorder, postorder, inorder.begin(), inorder.end()));
    }
};