// Itrative
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        stack<pair<TreeNode*,int>>s;
        s.push({root,0});
        while(!s.empty()){
            TreeNode*p=s.top().first;
            int num=s.top().second;
            s.pop();
            num=(num<<1)|p->val;
            if(p->left==NULL && p->right==NULL) sum+=num;
            if(p->right) s.push({p->right,num});
            if(p->left) s.push({p->left,num});
        }
        return sum;
    }
};

// Recursive
class Solution {
    int sum=0;
public:
    void preorder(TreeNode* root,int num){
        if(root==NULL) return;
        num=(num<<1) | root->val;
        if(root->left==NULL && root->right==NULL) sum+=num;
        preorder(root->left,num);
        preorder(root->right,num);
    }
    int sumRootToLeaf(TreeNode* root) {
        preorder(root,0);
        return sum;
    }
};