class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    vector<int> r;
    queue<TreeNode*> q;
    int count=1;
    q.push(root);
    q.push(NULL);
    while(1){
        if(q.front()==NULL){
            q.pop();
            if(count%2==0) reverse(r.begin(),r.end());
            ans.push_back(r);
            if (q.empty()) return ans;
            q.push(NULL);
            r.resize(0);
            count++;
            continue;
        }
        
            r.push_back((q.front())->val);
            if(q.front()->left)q.push((q.front())->left); 
            if(q.front()->right)q.push((q.front())->right);
            
            q.pop();
    }
    return ans;

    }
};
