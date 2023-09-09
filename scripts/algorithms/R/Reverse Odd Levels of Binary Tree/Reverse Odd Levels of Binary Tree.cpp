// Runtime: 210 ms (Top 42.9%) | Memory: 91.61 MB (Top 5.0%)

class Solution {
public:
    vector<int> traverse;
    TreeNode* reverseOddLevels(TreeNode* root) {
        bool oddLevel = false;
        auto Root = root;
        queue<TreeNode*> q;
        q.push({root});
        
        while(q.size()) {
            int cnt = q.size();
            vector<int> temp;
            
            while(cnt--) {
                auto node = q.front();
                q.pop();
                
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(oddLevel) {
                reverse(temp.begin(), temp.end());
                for(auto a : temp) traverse.push_back(a);
                oddLevel = false;
            } else {
                for(auto a : temp) traverse.push_back(a);
                oddLevel = true;
            }      
        }
        
        // Create Binary Tree from Vector
        queue<TreeNode*> Q;
        Q.push({Root});
        int j = 1;
        
        while(Q.size() && j < traverse.size()) {
            int cnt = Q.size();
            while(cnt--) {
                auto node = Q.front();
                Q.pop();
                
                if(j < traverse.size()) {
                    node->left = new TreeNode(traverse[j++]);
                }
                if(j < traverse.size()) {
                    node->right = new TreeNode(traverse[j++]);
                }
                if(node->left) {
                    Q.push(node->left);
                }
                if(node->right) {
                    Q.push(node->right);
                }
            }
        }
        return Root;
    }
};