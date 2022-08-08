class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        deque<int>dq;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                dq.push_back(grid[i][j]);
            }
        }
        
        int last = dq.size()-1;
        while(k--){
            int a = dq[last];
            dq.push_front(a);
            dq.pop_back();
        }
        
        int p = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                grid[i][j] = dq[p];
                p++;
            }
        }
        
        return grid;
    }
};
