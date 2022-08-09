class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0.00000;
        for(int i = 0; i<points.size(); ++i)
            for(int j = 0; j<points.size(); ++j)
                if(i!=j)
                    for(int k = 0; k<points.size(); ++k)
                        if(k!=i and k!=j)
                        {
                            //For triangle formed by 3 points a,b and c: the area will be = 1/2 * [(xa*yb + xb*yc + xc*ya) - (ya*xb + yb*xc + yc*xa)]
                            ans = max(ans, 0.50000 * (points[i][0]*points[j][1] + points[j][0]*points[k][1] + points[k][0]*points[i][1] - points[i][1]*points[j][0] - points[j][1]*points[k][0] - points[k][1]*points[i][0]));
                        }
        return ans;
    }
};
