class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> pa;
        int at_start=0;
        for(auto point:points)
        {
            if(point[0]==location[0] && point[1]==location[1])
                at_start++;
            else
            {
                double ang = atan2(point[1]-location[1], point[0]-location[0]) * 180.0 /M_PI;
                if(ang<0)
                    ang+=360;
                pa.push_back(ang);
            }
        }
        sort(pa.begin(), pa.end());
        int n=pa.size();   
        int l = 0, ret=0;
        for(int i=0; i<n; i++)
            pa.push_back(pa[i] + 360);
        for(int r=0; r<pa.size(); r++)
        {
            while((pa[r]-pa[l])>angle)
                l++;
            ret = max(ret, r-l+1);
        }
        return ret+at_start;
    }
};
