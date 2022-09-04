// Runtime: 43 ms (Top 98.68%) | Memory: 41.5 MB (Top 43.83%)
class Solution {
public:
    void sumGparent(TreeNode* child, int& sum, TreeNode* parent, TreeNode* Gparent){
        if(!child) return;
        if(Gparent) if(Gparent->val % 2 ==0) sum += child->val;
        sumGparent(child->left, sum, child, parent);
        sumGparent(child->right, sum, child, parent);
    }

    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        int sum=0;
        sumGparent(root, sum, NULL, NULL); // (child, sum, parent, grand-parent)
        return sum;
    }
};