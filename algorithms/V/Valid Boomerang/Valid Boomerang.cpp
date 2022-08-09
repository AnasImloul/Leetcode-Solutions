class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if (points.size()<=2) return false;
        int x0=points[0][0], y0=points[0][1];
        int x1=points[1][0], y1=points[1][1];
        int x2=points[2][0], y2=points[2][1];
        int dx1=x1-x0, dy1=y1-y0;
        int dx2=x2-x1, dy2=y2-y1;
        if (dy1*dx2==dy2*dx1) return false;
        return true;
    }
};
