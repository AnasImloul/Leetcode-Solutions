// Runtime: 12 ms (Top 70.59%) | Memory: 17.4 MB (Top 21.88%)
/*
Run BFS and store the index of the node when it was stored in the flattened manner.
Take the diff of each of the level and keep traking of max value

 */
class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            res = max(res, q.back().second - q.front().second + 1);
            int start = q.front().second;
            while(n--){
                TreeNode* p = q.front().first;
                long long ind = q.front().second - start;
                q.pop();
                if(p->left) q.push({p->left, ind*2 + 1});
                if(p->right) q.push({p->right, ind*2 + 2});
            }
        }
        return res;
    }
};