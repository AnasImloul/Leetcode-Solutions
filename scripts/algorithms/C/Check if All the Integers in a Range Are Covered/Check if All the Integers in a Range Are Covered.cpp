class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int n = ranges.size();
        
        sort(ranges.begin(), ranges.end());
        
        if(left < ranges[0][0])                 //BASE CASE
            return false;
        
        bool ans = false;
        
        for(int i = 0; i < n; i++){
            if(left>=ranges[i][0] && left<=ranges[i][1]){
                left = ranges[i][1]+1;
            }
            if(left > right){
                ans = true;
                break;
            }
        }
        return ans;
    }
};
