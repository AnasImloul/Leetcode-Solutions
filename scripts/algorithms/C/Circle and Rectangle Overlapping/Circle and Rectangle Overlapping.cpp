// Runtime: 0 ms (Top 100.00%) | Memory: 5.9 MB (Top 20.00%)
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //nearest_x = x1 when xCenter<x1<x2 (OR) x2 when x1<x2<xCenter (OR) xCenter when x1<xCenter<x2
        int nearest_x = (xCenter < x1) ? x1 : (xCenter > x2) ? x2 : xCenter;
        //same logic for nearest_y as in nearest_x
        int nearest_y = (yCenter < y1) ? y1 : (yCenter > y2) ? y2 : yCenter;
        int dist_x = xCenter - nearest_x, dist_y = yCenter - nearest_y;
        return dist_x * dist_x + dist_y * dist_y <= radius * radius;
    }
};