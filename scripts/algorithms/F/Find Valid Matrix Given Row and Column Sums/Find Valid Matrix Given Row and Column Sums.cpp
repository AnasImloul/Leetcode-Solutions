class Solution {
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int nRow = rowSum.size();
		int nCol = colSum.size();

		vector<vector<int>> res(nRow, vector<int> (nCol, 0));

		int i = 0, j = 0;
		while(i < nRow and j < nCol){
			if(rowSum[i] < colSum[j]){
				res[i][j] = rowSum[i];
				colSum[j] -= rowSum[i];
				rowSum[i++] = 0;
			}
			else{
				res[i][j] = colSum[j];
				rowSum[i] -= colSum[j];
				colSum[j++] = 0;
			}
		}
		return res;
	}
};