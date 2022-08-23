// Runtime: 13 ms (Top 59.60%) | Memory: 10.2 MB (Top 67.84%)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        vector<int>sk;
        int x,y,maxy=0;
        for(int i=0;i<points.size()-1;i++){
            for(int j=0;j<points[i].size()-1;j++){
                x=abs(points[i][j]-points[i+1][j]);
                y=abs(points[i][j+1]-points[i+1][j+1]);
                maxy+=std::max(x,y);
            }
        }
        return maxy;
    }
};