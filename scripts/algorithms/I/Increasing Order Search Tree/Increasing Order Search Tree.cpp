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
    TreeNode* temp;
    vector<int>z;
    TreeNode* increasingBST(TreeNode* root) 
    {  
        incresing(root);    
        sort(z.begin(), z.end());
        temp = new TreeNode(z[0]);
        create(temp, z);
        return temp;
    }
    void incresing(TreeNode* root)
    {
        if(root == NULL)  return;
        
        z.push_back(root->val);
        incresing(root->left);
        incresing(root->right);        
    }
    void create(TreeNode* create, vector<int> ze)
    {
          
        for(int i = 1; i<ze.size(); i++)
        {
            cout<<ze[i]<<endl;
            create->right = new TreeNode(ze[i]);
            create = create->right;
        }       
    }
};
