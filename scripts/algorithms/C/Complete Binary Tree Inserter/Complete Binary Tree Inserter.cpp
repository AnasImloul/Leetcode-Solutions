// Runtime: 30 ms (Top 73.79%) | Memory: 22.7 MB (Top 36.12%)
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
class CBTInserter {
public:
    vector<TreeNode*> arr;

    CBTInserter(TreeNode* root) {

        arr.push_back(root);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            if(q.front() -> left != NULL){
                arr.push_back(q.front() -> left);
                q.push(q.front() -> left);
            }
            if(q.front() -> right != NULL){
                arr.push_back(q.front() -> right);
                q.push(q.front() -> right);
            }
            q.pop();

        }
    }

    int insert(int val) {

        TreeNode* new_node = new TreeNode(val);
        arr.push_back(new_node);
        int parent_index = (arr.size()-2)/2;
        if(2*parent_index +1 == arr.size()-1){arr[parent_index] -> left = new_node;}
        else{arr[parent_index] -> right = new_node;}
        return arr[parent_index] -> val;
    }

    TreeNode* get_root() {
        return arr[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */