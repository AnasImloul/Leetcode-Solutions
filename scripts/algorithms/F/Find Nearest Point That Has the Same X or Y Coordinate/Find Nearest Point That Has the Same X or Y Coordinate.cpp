// Runtime: 362 ms (Top 9.60%) | Memory: 59.3 MB (Top 73.30%)
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int pos = -1;
        int ans = INT_MAX;

        for(int i=0; i<points.size(); i++){
            if(points[i][0] == x or points[i][1] == y){
                int dist = abs(x-points[i][0]) + abs(y-points[i][1]);
                if(dist < ans){
                    pos = i;
                    ans = dist;
                }
            }
        }
       return pos;
    }
};