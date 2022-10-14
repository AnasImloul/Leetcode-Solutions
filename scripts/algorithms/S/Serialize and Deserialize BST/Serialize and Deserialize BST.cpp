// Runtime: 96 ms (Top 19.45%) | Memory: 30.9 MB (Top 22.86%)
class Codec
{
    public:

    string pre(TreeNode * root)
    {
        if(root==NULL)
            return "";

        int temp = root->val;
        string tempz = to_string(temp);

        string l = pre(root->left);
        string r = pre(root->right);

        return (tempz + "," + l + "," + r);
    }

    vector<int> parse_string(string data)
    {
        vector<int> ans;
        string temp = "";
        int n=data.size();

        for(int i=0;i<n; ++i)
        {
            if(data[i]==',')
            {
                if(temp.size()==0)
                    continue;
                else
                {
                    int val = stoi(temp);
                    ans.push_back(val);
                    temp="";
                }
            }
            else
                temp += data[i];
        }
        return ans;
    }

    TreeNode * make_tree(vector<int>& preorder, int min_val, int max_val, int& preorder_idx, int n)
    {
        if(preorder_idx == n)
            return NULL;
        int val = preorder[preorder_idx];
        if(min_val <= val and val <= max_val)
        {
            TreeNode * curr = new TreeNode(val);
            preorder_idx++;
            curr->left = make_tree(preorder, min_val, val-1, preorder_idx, n);
            curr->right = make_tree(preorder, val+1, max_val, preorder_idx, n);
            return curr;
        }
        else
            return NULL;
    }

    string serialize(TreeNode* root)
    {
        string traversal = pre(root);
        //cout<<traversal<<endl;
        return traversal;
    }

    TreeNode* deserialize(string data)
    {
        if(data.size()==0)
            return NULL;
        vector<int> traversal = parse_string(data);

        // for(auto x:traversal)
        // cout<<x<<" ";

        int preorder_idx = 0;
        TreeNode * root = make_tree(traversal, INT_MIN, INT_MAX, preorder_idx, traversal.size());

        return root;
    }
};
