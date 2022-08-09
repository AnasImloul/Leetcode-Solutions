 class Solution {
public:
    void solve(Node*root,vector<int>&ans){
        if(root==NULL)return;
        for(int i=0;i<root->children.size();i++){
            solve(root->children[i],ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
		
