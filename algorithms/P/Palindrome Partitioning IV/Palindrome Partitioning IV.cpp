class Solution {
public:
	vector<vector<int>> dp1;
	bool isPalindrome(string& s, int i, int j) {
		if (i >= j) return true;
		if (dp1[i][j] != -1) return dp1[i][j];
		if (s[i] == s[j]) return dp1[i][j] = isPalindrome(s, i + 1, j - 1);
		return dp1[i][j] = false;
	}
	bool checkPartitioning(string s) {
		int n = s.size();
		dp1.resize(n,vector<int> (n,-1));
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n-1;j++){
				if(isPalindrome(s,0,i) && isPalindrome(s,i+1,j) && isPalindrome(s,j+1,n-1))
					return true;
			}
		}
		return false;
	}
};
