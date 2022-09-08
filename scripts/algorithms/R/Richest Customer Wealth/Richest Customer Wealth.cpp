// Runtime: 9 ms (Top 48.51%) | Memory: 7.7 MB (Top 99.02%)
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(int i =0;i<accounts.size();i++){
            int temp = 0;
            for(int j = 0;j<accounts[i].size();j++){
                temp+=accounts[i][j];
            }
            res = max(res,temp);
        }
        return res;
    }
};