class Solution {
    vector<TreeNode*> leaves;
    unordered_map<TreeNode* , TreeNode*> pof;
    void makeGraph(unordered_map<TreeNode* , TreeNode*> &pof, TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right){
            leaves.push_back(root);
            return;
        }
        if(root->left) pof[root->left]=root;
        if(root->right) pof[root->right]=root;
        makeGraph(pof, root->left);
        makeGraph(pof, root->right);
    }
public:
    int countPairs(TreeNode* root, int distance) {
        leaves={};
        makeGraph(pof, root);
        int ans=0;
        queue<pair<TreeNode*, int>> q;
        for(auto &l: leaves){
            q.push({l, 0}); 
            unordered_set<TreeNode*> isVis;
            while(q.size()){
                auto [cur, dist]=q.front();
                q.pop();
                if(isVis.count(cur) || dist>distance) continue;
                isVis.insert(cur);
                if(!cur->left && !cur->right && cur!=l && dist<=distance){
                    ans++;
                    continue;
                }
                if(cur->left && !isVis.count(cur->left)) q.push({cur->left, dist+1});
                if(cur->right && !isVis.count(cur->right)) q.push({cur->right, dist+1});
                if(pof.count(cur) && !isVis.count(pof[cur])) q.push({pof[cur], dist+1});
            }
        }
        return ans>>1;
    }
};
