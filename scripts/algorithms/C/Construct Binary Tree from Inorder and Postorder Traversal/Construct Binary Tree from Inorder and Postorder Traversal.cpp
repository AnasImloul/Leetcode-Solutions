class Solution {
public:
    TreeNode* buildTree(vector<int>& ino, vector<int>& post) {
    int i1 = post.size()-1;
        return solve(i1,ino,post,0,ino.size()-1);
    }
    TreeNode* solve(int &i,vector<int> &in,vector<int> &post,int l,int r){
        if(l>r)return NULL;
        int x = r;
        while(post[i] != in[x]){
            x--;
        }
        i--;
        // cout<<in[x]<<" ";
        TreeNode* root = new TreeNode(in[x]);
        root->right = solve(i,in,post,x+1,r);
        root->left = solve(i,in,post,l,x-1);
        return root;
    }
};