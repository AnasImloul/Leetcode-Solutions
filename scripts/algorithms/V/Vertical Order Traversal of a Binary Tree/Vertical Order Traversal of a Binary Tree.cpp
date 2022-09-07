// Runtime: 6 ms (Top 74.70%) | Memory: 12.3 MB (Top 80.06%)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // hd - horizontal distance
    // vertical order traversal starts from least hd to highest hd
    // on moving left hd decreases by 1, on moving right it increases by 1

    // should do level order traversal to get the nodes with same hd in correct order

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();
            map<int,multiset<int>> temp;
            for(int i=0;i<sz;i++){
                auto pr = q.front();
                q.pop();
                temp[pr.second].insert(pr.first->val);
                if(pr.first->left != NULL){
                    q.push({pr.first->left,pr.second-1});
                }
                if(pr.first->right != NULL){
                    q.push({pr.first->right,pr.second+1});
                }
            }
            for(auto pr:temp){
                    for(auto val:pr.second){
                        mp[pr.first].push_back(val);
                    }
                }
        }
        vector<vector<int>> ans;
        for(auto pr:mp){
            vector<int> temp;
            for(auto val:pr.second){
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};