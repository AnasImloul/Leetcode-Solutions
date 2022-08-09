class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        multimap<int,vector<int>> mp;
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                    mp.insert(pair<int,vector<int>>(abs(i-rCenter)+abs(j-cCenter),{i,j})); //map will sort the value based on key(distance)    
                }
            }
        for(auto itr = mp.begin();itr != mp.end();itr++){
            ans.push_back(itr->second);
        }
        return ans;
    }
};
