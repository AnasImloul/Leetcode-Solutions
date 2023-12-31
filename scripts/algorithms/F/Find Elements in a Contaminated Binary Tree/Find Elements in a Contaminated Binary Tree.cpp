// Runtime: 31 ms (Top 65.66%) | Memory: 22.10 MB (Top 59.04%)

class FindElements
{
public:
    unordered_map<int,int>m;

    FindElements(TreeNode* root)
    {
        if(root)
        {
            root->val = 0;
            queue<TreeNode*> q;
            q.push(root);
            m[0]++;

            while(!q.empty())
            {
                TreeNode* temp = q.front();
                q.pop();
                int x = temp->val;
                if(temp->left)
                {
                    temp->left->val = x*2 + 1;

                    m[x*2 + 1]++;
                    q.push(temp->left);
                }

                if(temp->right)
                {
                    temp->right->val = x*2 + 2;

                    m[x*2 + 2]++;
                    q.push(temp->right);
                }
            }
        }
    }

    bool find(int target)
    {
        return (m.find(target) != m.end());
    }
};
