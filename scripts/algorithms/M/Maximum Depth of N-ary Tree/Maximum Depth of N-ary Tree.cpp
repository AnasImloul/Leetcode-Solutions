class Solution {
public:
    int maxDepth(Node* root) 
    {
        if(root == NULL)
        {
            return 0;
        }
        int dep = 1, mx = INT_MIN;
        helper(root, dep, mx);
        return mx;
    }
    
    void helper(Node *root, int dep, int& mx)
    {
        if(root->children.size() == 0)
        {
            mx = max(mx, dep);
        }
        for(int i = 0 ; i<root->children.size() ; i++)
        {
            helper(root->children[i], dep+1, mx);
        }
    }
};
