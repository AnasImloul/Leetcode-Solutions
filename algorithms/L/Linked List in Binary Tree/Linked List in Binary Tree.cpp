class Solution {
public:
    bool func(ListNode *head,TreeNode *root){
        if(!head) return true;
        if(!root) return false;
        if(head->val == root->val) return func(head->next,root->left) or func(head->next,root->right);
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        if(func(head,root)) return true;
        return isSubPath(head,root->left) or isSubPath(head,root->right); 
    }
};
