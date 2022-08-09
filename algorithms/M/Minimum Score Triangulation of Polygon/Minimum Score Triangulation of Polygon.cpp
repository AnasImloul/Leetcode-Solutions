class Solution {
public:
	int f(int i,int j,vector<int>& values,vector<vector<int>> &dp){
		if(i == j || i+1 == j)    return 0;
		if(dp[i][j] != -1)        return dp[i][j];
		int res = INT_MAX;
		for(int k = i+1;k < j;k++)
		{
			int temp = values[i]*values[j]*values[k] + f(k,j,values,dp) + f(i,k,values,dp);
			res = min(res,temp);
		}
		return dp[i][j] = res;
	}

	int minScoreTriangulation(vector<int>& values) {
		int n = values.size();
		vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
		return f(0,n - 1,values,dp);
	}
