class Solution {
private:
	void dfs(TreeNode* root,int &ans,unordered_map<int,int> &m){

		if(!root) return;
		m[root -> val]++;

		if(!root -> left and !root -> right){
			int oddCnt = 0;
			for(auto it : m){
				if(it.second % 2 != 0) oddCnt++;
			}
			if(oddCnt <= 1) ans++;
		}


		dfs(root -> left,ans,m);
		dfs(root -> right,ans,m);

		m[root -> val]--;

	}
public:
	int pseudoPalindromicPaths (TreeNode* root) {

		if(root == NULL) return 0;

		int ans = 0;

		unordered_map<int,int> m;

		dfs(root,ans,m);

		return ans;

	}
};