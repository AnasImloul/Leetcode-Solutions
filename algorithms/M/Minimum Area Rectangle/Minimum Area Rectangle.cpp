/*
    https://leetcode.com/problems/minimum-area-rectangle/
    
    TC: O(n^2)
    SC: O(n)
    
    The major challenge is to find 4 points that form a rectangle. 
    Brute force approach is to have 4 loops each controlling a coordinate.
    
    To make this faster, we use hashing to store the y coordinates for each of the x coordinate.
    Using 2 loops, fixing one coordinate each, we treat them as diagonals and check for the existence
    of other two pts. If we find the other two pts, then compare the area and proceed.
*/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // We need to find out 4 points that form a rectangle
        // We can fix two points, but need an efficient way to confirm the other two
        
        // Store all the vertical pts for each of the x coordinates
        // <x coordinate, Set(y coordinate)>
        unordered_map<int, unordered_set<int> > vertical_pts;
        for(auto point: points)
            vertical_pts[point[0]].emplace(point[1]);
        
        int min_area = INT_MAX;
        
        // We need pt1 and pt2 to be diagonal points
        for(int pt1 = 0; pt1 < points.size(); pt1++)
            for(int pt2 = pt1 + 1; pt2 < points.size(); pt2++) {
                int x1 = points[pt1][0], y1 = points[pt1][1];
                int x2 = points[pt2][0], y2 = points[pt2][1];
                
                // check if the two points are either on the same horizontal or vertical line
                if(x1 == x2 || y1 == y2)
                    continue;
                
                // Once we know that the two points are not on the same vertical or horizontal line,
                // We can treat them as diagonals. Now we check for the other two points.
                /*
                    Let the diagonal pts be C (pt1) and D (pt2)
                    A-----B
                    |     |
                    C-----D
                    
                    Check if A and D exists. 
                    NOTE: Position of C and B might be reversed or at A and D position as well.
                    But below code will work since it checks for the other pts by creating the data from these diagonal pts
                */
                
                // A and D exists
                if(vertical_pts[x1].count(y2) && vertical_pts[x2].count(y1)) {
                    min_area = min(min_area, (abs(x2 - x1) * abs(y2 - y1)));
                }
            }
        
        return min_area == INT_MAX ? 0 : min_area;
    }
};
