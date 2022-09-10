// Runtime: 304 ms (Top 89.53%) | Memory: 66.3 MB (Top 79.15%)
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(begin(points),end(points));
        int n=points.size();
        int m=0;
        for(int i=0;i<n-1;i++)
            m=max(points[i+1][0]-points[i][0],m);
        return m;
    }
};