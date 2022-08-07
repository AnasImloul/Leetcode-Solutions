class Solution 
{
    public:
    vector<TreeNode*> solve(int start, int end)
    {
        //base case
        if(start>end){
            return {NULL};
        }
        vector<TreeNode*> lChild, rChild, res;
        //forming a tree, by keeping each node as root node
        for(int i=start; i<=end; i++)
        {
            //don't create node here, bcz for each combination of subtree, node with new address has to be generated

            //recursive call for left,right child, they will return vector of all possible subtrees
            lChild = solve(start, i-1);
            rChild = solve(i+1, end);
            
            //for each subtree returned by lChild, forming combination with each subtree returned by rChild
            for(auto l: lChild)
            {
                for(auto r: rChild)
                {
                    //generating new node for each combination
                    TreeNode* node = new TreeNode(i);
                    //attaching left, right childs
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }            
        }
        //returning all possible subtrees
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};
