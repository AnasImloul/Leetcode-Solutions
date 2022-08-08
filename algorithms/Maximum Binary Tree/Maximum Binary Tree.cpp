
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
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return recur(0, nums.size() - 1, nums);
    }
    
    TreeNode* recur(int st, int en, vector<int> &ar)
    {
        if(st > en)
        {
            return NULL;
        }
        TreeNode* cur = new TreeNode();
        int maxm = -1, ind;
        for(int i = st; i <= en; i++)
        {
            if(maxm < ar[i])
            {
                maxm = ar[i];
                ind = i;
            }
        }
        
        cur->val = ar[ind];
        cur->left = recur(st, ind-1, ar);
        cur->right = recur(ind+1, en, ar);
        
        return cur;
    }
};