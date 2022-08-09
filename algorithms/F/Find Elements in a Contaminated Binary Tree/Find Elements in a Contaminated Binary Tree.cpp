/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    void initialize(TreeNode* root,unordered_set<int> &s){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            s.insert(t->val);
            if(t->left != NULL){
                t->left->val = 2*(t->val)+1;
                q.push(t->left);
            }
            if(t->right != NULL){
                t->right->val= 2*(t->val)+2;
                q.push(t->right);
            }
        }
    }
    unordered_set<int> s;
    FindElements(TreeNode* root) {
        root->val = 0;
        

        initialize(root,s);
        
    }
    
    bool find(int target) {
        if(s.find(target) != s.end())
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */```