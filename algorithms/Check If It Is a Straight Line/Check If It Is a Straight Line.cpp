class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n=coordinates.size();  
        int xdiff = coordinates[1][0] - coordinates[0][0]; 
        int ydiff = coordinates[1][1] - coordinates[0][1];
        
        int cur_xdiff, cur_ydiff;
        
        for(int i=2; i<n; i++){
            
            cur_xdiff = coordinates[i][0] - coordinates[i-1][0];
            cur_ydiff = coordinates[i][1] - coordinates[i-1][1];
            
            if(ydiff*cur_xdiff!=xdiff*cur_ydiff) return false;
        }
        return true;
    }
};
