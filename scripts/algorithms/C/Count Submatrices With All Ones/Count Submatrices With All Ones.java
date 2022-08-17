class Solution {
	public int numSubmat(int[][] mat) {
		int n = mat.length;
		int m = mat[0].length;
		//left[i][j] indicates how many consecutive 1s are on the left of i, j
		//left[i][j] indicates how many consecutive 1s are above i, j
		//dp[i][j] represents the number of submatrices with i, j as the lower right corner
		int[][] left = new int[n][m];
		int[][] up = new int[n][m];
		int[][] dp = new int[n][m];
		up[0][0] = mat[0][0];
		left[0][0] = mat[0][0];
		dp[0][0] = mat[0][0];
		for(int i = 1; i < n; i++){
			if(mat[i][0] == 0){
				continue;
			}
			up[i][0] = mat[i][0];
			left[i][0] = left[i - 1][0] + 1;
			dp[i][0] = left[i][0];
		}

		for(int j = 1; j < m; j++){
			if(mat[0][j] == 0){
				continue;
			}
			up[0][j] = up[0][j - 1] + 1;
			left[0][j] = mat[0][j];
			dp[0][j] = up[0][j];
		}

		for(int i = 1; i < n; i++){
			for(int j = 1; j < m; j++){
				if(mat[i][j] == 0){
					continue;
				}
				up[i][j] = up[i][j - 1] + 1;
				left[i][j] = left[i - 1][j] + 1;
				int minHeight = up[i][j];
				for(int k = 0; k < left[i][j]; k++){
					minHeight = Math.min(minHeight, up[i - k][j]);
					dp[i][j] += minHeight;
				}
			}
		}
		int res = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				res += dp[i][j];
			}
		}
		return res;
	}
}