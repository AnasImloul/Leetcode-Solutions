//TC O(1) and O(H) Space

//MIMIC inorder
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        pushAll(root);
         // left is done
    }
    
    int next() {
        //root handled
        TreeNode* node = stk.top();
        int ans = node->val;
        stk.pop();
        
        //right handled
        pushAll(node->right);
        
        return ans;
        
    }
    
    bool hasNext() {
        return stk.size() != 0; // stk is empty then no next to show simple
    }
    
    void pushAll(TreeNode* root){
        //left part - as inorder is like Left left left, once a root is done then check right
        while(root!= NULL){
            stk.push(root);
            root = root->left;
        }
        
    }
};

