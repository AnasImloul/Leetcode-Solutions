// Runtime: 0 ms (Top 100.00%) | Memory: 6.6 MB (Top 31.22%)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());
        for(int i = 0; i<numRows; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    ans[i].push_back(1);
                }else{
                    ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
            }
        }
        return ans;
    }
};