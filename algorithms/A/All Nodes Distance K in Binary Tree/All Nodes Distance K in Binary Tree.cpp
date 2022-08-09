void makeParent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent)
{
	queue<TreeNode*> q;
	q.push(root);

	while(q.empty()==false)
	{
		TreeNode *curr = q.front();
		q.pop();

		if(curr->left!=NULL)
		{
			parent[curr->left] = curr;
			q.push(curr->left);
		}

		if(curr->right!=NULL)
		{
			parent[curr->right] = curr;
			q.push(curr->right);
		}
	}
}

class Solution {
public:

void solve(TreeNode* target, unordered_map<TreeNode*,TreeNode*> &parent,unordered_map<TreeNode*,bool> &visited,                     vector<int> &res, int k)
{        
    if(k==0){
        res.push_back(target->val);
        return;
    }
    
    queue<TreeNode *>q;
    int distance = 0;
    
    q.push(target);
    visited[target] = 1;
    
    while(q.empty()==false)
    {
        int count = q.size();
        distance++;// increment distance value for current level of our level order traversal
        
        for(int i=0;i<count;i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            
            if(curr->left!=NULL && visited[curr->left]==false)
            {
                visited[curr->left] = true;
                q.push(curr->left);
                
                if(distance==k)// when we reach the node at distance = k, push it to res
                    res.push_back(curr->left->val);
            }
            
            if(curr->right!=NULL && visited[curr->right]==false)
            {
                visited[curr->right] = true;
                q.push(curr->right);
                
                if(distance==k)// when we reach the node at distance = k, push it to res
                    res.push_back(curr->right->val);
            }
            
            if(parent[curr] && visited[parent[curr]]==false)
            {
                visited[parent[curr]] = true;
                q.push(parent[curr]);
                
                if(distance==k)// when we reach the node at distance = k, push it to res
                    res.push_back(parent[curr]->val);
            }
        }
        
        if(distance==k)// if in curr iteration all k distances nodes have been pushed, we break
            break;
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
{
    unordered_map<TreeNode*,TreeNode*> parent;
    makeParent(root,parent);
    
    unordered_map<TreeNode*,bool> visited;
    vector<int> ans;
    
    solve(target,parent,visited,ans,k);// begin from target Node
    return ans;
}
