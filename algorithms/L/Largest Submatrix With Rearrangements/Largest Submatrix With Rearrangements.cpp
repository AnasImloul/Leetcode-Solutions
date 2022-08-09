class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<int> height(n, 0);
		
		// view each row and its above as pillars 
        for(int i = 0; i < m; ++i){
			// calculate heights
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }
			
			// sort pillars
            vector<int> order_height = height;
            sort(order_height.begin(), order_height.end());
			
			// iterate to get the maxium rectangle
            for(int j = 0; j < n; ++j){
                ans = max(ans, order_height[j] * (n - j));
            }
        }
        return ans;
    }
};
